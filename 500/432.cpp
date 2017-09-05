/*
    Implement a data structure supporting the following operations:

    Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
    Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
    GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
    GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
    Challenge: Perform all these in O(1) time complexity.
*/

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        minFreq = 0;
        maxFreq = 0;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int prevFreq = keyMap[key]++;
        
        if(freqMap.find(keyMap[key]) == freqMap.end())
            freqMap[keyMap[key]] = unordered_set<string>();
        
        freqMap[keyMap[key]].insert(key);
        
        if(prevFreq == 0)
            minFreq = 1;
        else
        {
            freqMap[prevFreq].erase(key);
            if(freqMap[minFreq].empty())
                minFreq = keyMap[key];
        }
        
        maxFreq = max(maxFreq, keyMap[key]);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(keyMap.find(key) == keyMap.end())
            return;
        
        int prevFreq = keyMap[key]--;
        if(keyMap[key] == 0)
            keyMap.erase(key);
        
        freqMap[prevFreq].erase(key);
        if(prevFreq > 1)
            freqMap[keyMap[key]].insert(key);
        
        while(maxFreq > 0 && freqMap[maxFreq].empty())
            --maxFreq;
        
        if(maxFreq == 0)
            minFreq = maxFreq;
        else
            for(minFreq = 1; minFreq < maxFreq && freqMap[minFreq].empty(); ++minFreq) {}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return freqMap[maxFreq].empty() ? "" : *freqMap[maxFreq].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return freqMap[minFreq].empty() ? "" : *freqMap[minFreq].begin();
    }
    
private:
    unordered_map<string, int> keyMap;
    unordered_map<int, unordered_set<string>> freqMap;
    
    int maxFreq;
    int minFreq;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
