/*
	Given a collection of numbers that might contain duplicates, return all possible unique permutations.

	For example,
	[1,1,2] have the following unique permutations:
	[
	  [1,1,2],
	  [1,2,1],
	  [2,1,1]
	]
*/

class Solution {
public:
    void getPermutationUnique(vector<int>& nums, int start, vector<vector<int>>& permutations)
    {
        if(start == nums.size() - 1)
            permutations.push_back(nums);
        else
        {
            for(int i = start; i < nums.size();)
            {
                for(int j = i; j > start; --j)
                    swap(nums[j - 1], nums[j]);
                getPermutationUnique(nums, start + 1, permutations);
                for(int j = start; j < i; ++j)
                    swap(nums[j], nums[j + 1]);
                for(++i; i < nums.size() && nums[i] == nums[i - 1]; ++i){}
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        getPermutationUnique(nums, 0, permutations);
        return permutations;
    }
};
