/*
    Given an array of integers and an integer k, find out 
    whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
    and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0 || nums.empty())
            return false;
            
        distinctNumbersWithinRangeK.insert(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
        {
            if(distinctNumbersWithinRangeK.find(nums[i]) != distinctNumbersWithinRangeK.end())
                return true;
                
            if(i >= k)
                distinctNumbersWithinRangeK.erase(nums[i - k]);
                
            distinctNumbersWithinRangeK.insert(nums[i]);
        }
        
        return false;
    }
    
private:
    unordered_set<int> distinctNumbersWithinRangeK;
};
