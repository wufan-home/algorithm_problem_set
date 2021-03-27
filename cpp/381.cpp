/*
    Design a data structure that supports all following operations in average O(1) time.

    Note: Duplicate elements are allowed.
    insert(val): Inserts an item val to the collection.
    remove(val): Removes an item val from the collection if present.
    getRandom: Returns a random element from current collection of elements. 
    The probability of each element being returned is linearly related to the number of same value the collection contains.
    Example:

    // Init an empty collection.
    RandomizedCollection collection = new RandomizedCollection();

    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    collection.insert(1);

    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    collection.insert(1);

    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    collection.insert(2);

    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    collection.getRandom();

    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    collection.remove(1);

    // getRandom should return 1 and 2 both equally likely.
    collection.getRandom();
*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(valueToIndexSet.find(val) != valueToIndexSet.end())
        {
            valueList.push_back(val);
            valueToIndexSet[val].insert(valueList.size() - 1);
            return false;
        }
        else
        {
            valueList.push_back(val);
            valueToIndexSet[val] = unordered_set<int>();
            valueToIndexSet[val].insert(valueList.size() - 1);
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(valueToIndexSet.find(val) == valueToIndexSet.end())
            return false;
        
        int lastValue = valueList.back();
        int lastIndex = valueList.size() - 1;
        
        if(lastValue != val)
        {
            int removeIndex = *valueToIndexSet[val].begin();
            swap(valueList[removeIndex], valueList[lastIndex]);
            valueToIndexSet[lastValue].insert(removeIndex);
            valueToIndexSet[val].erase(removeIndex);
            if(valueToIndexSet[val].empty())
                valueToIndexSet.erase(val);
        }
        
        valueList.pop_back();
        valueToIndexSet[lastValue].erase(lastIndex);
        if(valueToIndexSet[lastValue].empty())
            valueToIndexSet.erase(lastValue);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return valueList[rand() % valueList.size()];
    }
    
private:
    
    vector<int> valueList;
    unordered_map<int, unordered_set<int>> valueToIndexSet;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
