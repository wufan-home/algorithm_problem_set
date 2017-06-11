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

#include <forward_list>

class LFUCache {
public:
    LFUCache(int capacity) {
        cache = unordered_map<int, vector<int>>();
        freqToKeys = unordered_map<int, list<int>>();
        mCapacity = capacity;
        transactionNo = 0;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        cache[key][2] = ++transactionNo;
        return cache[key][0];
    }
    
    void put(int key, int value) {
        if(mCapacity < 1)
            return ;

        int oldFreq = -1;
        int newFreq = -1;
        if(cache.find(key) != cache.end())
        {
            if(cache[key][0] != value)
                cache[key][0] = value;

            oldFreq = cache[key][1]++;
            newFreq = cache[key][1];
            cache[key][2] = ++transactionNo;
        }
        else 
        {
            if(cache.size() == mCapacity)
            {
                int leastFreq = findMinimalFrequency();
                list<int>& tempList = freqToKeys[leastFreq];
                int removeKey = -1;
                for(list<int>::iterator it = tempList.begin(); it != tempList.end(); ++it)
                {
                    //cout << *it << ", " << cache[*it][2] << ", " << removeKey << ", " << (removeKey != - 1 ? cache[removeKey][2] : -1) << endl;
                    if(removeKey == -1 || cache[*it][2] < cache[removeKey][2])
                    {
                        removeKey = *it;
                    }
                }
                
                cache.erase(removeKey);
                freqToKeys[leastFreq].remove(removeKey);
            }
            
            cache[key] = vector<int>(3, 1);
            cache[key][0] = value;
            newFreq = 1;
            cache[key][2] = 0;
        }
        
        if(oldFreq > 0)
            freqToKeys[oldFreq].remove(key);
        
        if(freqToKeys.find(newFreq) == freqToKeys.end())
            freqToKeys[newFreq] = list<int>(1, key);
        else
            freqToKeys[newFreq].push_back(key);
    }
    
private:
    int findMinimalFrequency()
    {
        int freq = 1;
        for(unordered_map<int, list<int>>::iterator it = freqToKeys.begin(); it != freqToKeys.end(); ++it)
        {
            if(it->second.size() > 0 && it->first < freq)
                freq = it->first;
        }
        
        return freq;
    }
    
    unordered_map<int, vector<int>> cache;
    unordered_map<int, list<int>> freqToKeys;
    int mCapacity;
    int transactionNo;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
