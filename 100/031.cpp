/*
  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
  The replacement must be in-place, do not allocate extra memory.
  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1

  Solution: 
*/

vector<int> nextPermutation(vector<int> &nums)
{
        int cur = nums.size() - 1;
        for(; cur > 0; --cur)
        {
		if(nums[cur] > nums[cur - 1])
		{
			int j = nums.size() - 1;
			for(; j >= cur && nums[j] <= nums[cur - 1]; --j) {}
			swap(nums[cur - 1], nums[j]);
			break;
		}
        }
        for(int l = cur, r = nums.size() - 1; l < r; ++l, --r)
		swap(nums[l], nums[r]);
        return nums;
}
