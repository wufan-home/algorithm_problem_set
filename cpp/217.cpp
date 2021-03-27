/*
    Given an array of integers, find if the array contains any duplicates. 
    Your function should return true if any value appears at least twice in the array, 
    and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(distincts.find(nums[i]) != distincts.end())
                return true;
                
            distincts.insert(nums[i]);
        }
        
        return false;
    }
    
private:
    unordered_set<int> distincts;
};
