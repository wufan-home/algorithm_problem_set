/*
  Given an unsorted integer array, find the first missing positive integer.
  For example,
  Given [1,2,0] return 3,
  and [3,4,-1,1] return 2.
  Your algorithm should run in O(n) time and uses constant space.
  Show Tags
  Show Similar Problems
*/

int firstMissingPositive(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); ++i)
	{
		while(nums[i] != i + 1)
		{
			if(nums[i] <= 0 || nums[i] > nums.size())
			{
				nums[i] = -1;
				break;
			}

			if(nums[nums[i] - 1] != nums[i])
				swap(nums[nums[i] - 1], nums[i]);
			else
				break;
		}
		
		if(nums[i] != i + 1)
			nums[i] = -1;
	}
	
	for(int i = 0; i < nums.size(); ++i)
	{
		if(nums[i] == -1)
			return i + 1;
	}
	return nums.size() + 1;
}
