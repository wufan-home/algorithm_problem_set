/*
	Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

	Follow up:
	Could you do both operations in O(1) time complexity?

	Example:

	LRUCache cache = new LRUCache( 2 ); //capacity

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4
*/

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) 
    {
        int value = -1;
        if(hash.find(key) != hash.end())
        {
            value = hash[key].first;
            updateIterator(key);
        }
        
        return value;
    }
    
    void put(int key, int value) 
    {
        if(hash.find(key) != hash.end())
        {
            hash[key].first = value;
        }
        else
        {
            if(hash.size() == cap)
            {
                int removeKey = listFreq.back();
                listFreq.pop_back();
                hash.erase(removeKey);
            }

            hash[key] = make_pair(value, listFreq.cend());
        }
        
        updateIterator(key);
    }
    
private:
    void updateIterator(int key)
    {
        list<int>::const_iterator it = hash[key].second;
        
        if(it != listFreq.end())
            listFreq.erase(it);
        
        listFreq.push_front(key);
        hash[key].second = listFreq.cbegin();
    }
    
    int cap;
    list<int> listFreq;
    unordered_map<int, pair<int, list<int>::const_iterator>> hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// ================================

class LRUCache{
public:
    LRUCache(int capacity) : mCapacity(capacity), head(NULL), tail(NULL) {}
    
    int get(int key) {
        int value = -1;
        if(container.find(key) != container.end())
        {
            value = container[key].first;
            updatePriorityList(container[key].second);
        }
        
        return value;
    }
    
    void put(int key, int value) {
        if(container.find(key) != container.end())
        {
            container[key].first = value;
            updatePriorityList(container[key].second);
            return;
        }
        
        if(container.size() == mCapacity)
        {
            int removeKey = tail->key;
            if(tail->prev == NULL)
            {
                delete tail;
                head = NULL;
                tail = NULL;
            }
            else
            {
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
            
            container.erase(removeKey);
        }
        
        DoubleListNode *newNode = new DoubleListNode(key);
        container[key] = make_pair(value, newNode);
        newNode->next = head;
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }
    
private:
    struct DoubleListNode
    {
        int key;
        DoubleListNode *prev;
        DoubleListNode *next;
        
        DoubleListNode(int key) : key(key), prev(NULL), next(NULL) {}
    };
    
    void updatePriorityList(DoubleListNode *curNode)
    {
        if(curNode->prev != NULL)
        {
            DoubleListNode *prev = curNode->prev;
            DoubleListNode *next = curNode->next;
            curNode->prev = NULL;
            curNode->next = head;
            head->prev = curNode;
            head = curNode;
            
            prev->next = next;
            if(next == NULL)
                tail = prev;
            else
                next->prev = prev;
        }
    }

    int mCapacity;
    
    DoubleListNode *head;
    DoubleListNode *tail;
    
    unordered_map<int, pair<int, DoubleListNode *>> container;
};
