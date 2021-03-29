/*
    Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LFUCache cache = new LFUCache( 2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
*/

class LFUCache {
public:
    LFUCache(int capacity) {
        mCapacity = capacity;
        mMinFreq = 0;
        freqToItems[1] = list<int>();
    }
    
    int get(int key) {
        if(mCapacity == 0 || keyToInfo.find(key) == keyToInfo.end())
            return -1;
        
        int curFreq = ++keyToInfo[key].second;
        
        freqToItems[curFreq - 1].erase(keyToIterator[key]);
        freqToItems[curFreq].push_back(key);
        keyToIterator[key] = --freqToItems[curFreq].end();
        if(freqToItems[mMinFreq].empty())
            ++mMinFreq;
        
        return keyToInfo[key].first;
    }
    
    void put(int key, int value) {
        if(mCapacity == 0)
            return;
        
        if(keyToInfo.find(key) != keyToInfo.end())
        {
            keyToInfo[key].first = value;
            
            int curFreq = ++keyToInfo[key].second;
            
            freqToItems[curFreq - 1].erase(keyToIterator[key]);
            freqToItems[curFreq].push_back(key);
            keyToIterator[key] = --freqToItems[curFreq].end();
            if(freqToItems[mMinFreq].empty())
                ++mMinFreq;
            return;
        }
        
        if(keyToInfo.size() == mCapacity)
        {
            int removedKey = *(freqToItems[mMinFreq].begin());
            freqToItems[mMinFreq].pop_front();
            keyToInfo.erase(removedKey);
            keyToIterator.erase(removedKey);
        }
        
        keyToInfo[key] = make_pair(value, 1);
        freqToItems[1].push_back(key);
        keyToIterator[key] = --freqToItems[1].end();
        mMinFreq = 1;
    }
    
private:
    unordered_map<int, pair<int ,int>> keyToInfo;
    unordered_map<int, list<int>> freqToItems;
    unordered_map<int, list<int>::iterator> keyToIterator;
    
    int mCapacity;
    int mMinFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
