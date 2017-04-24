/*
  Given a collection of distinct numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

*/

class Solution {
public:
    void getPermutation(vector<int>& nums, int start, vector<vector<int>>& permutations)
    {
        if(start == nums.size() - 1)
            permutations.push_back(nums);
        else
        {
            for(int i = start; i < nums.size(); ++i)
            {
                swap(nums[start], nums[i]);
                getPermutation(nums, start + 1, permutations);
                swap(nums[start], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        getPermutation(nums, 0, permutations);
        return permutations;
    }
};
