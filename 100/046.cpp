/*
  Given a collection of distinct numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/

void DoPermute(vector<int>& nums, int cur, vector<vector<int>>& permutes)
{
        if(cur == nums.size() - 1)
		permutes.push_back(nums);
        else
        {
		for(int i = cur; i < nums.size(); ++i)
		{
			swap(nums[i], nums[cur]);
			DoPermute(nums, cur + 1, permutes);
			swap(nums[i], nums[cur]);
		}
        }
}
    
vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int>> permutes;
        DoPermute(nums, 0, permutes);
        return permutes;
}
