/*
  Find the kth largest element in an unsorted array. 
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  For example,
  Given [3,2,1,5,6,4] and k = 2, return 5.
  Note: 
  You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

int Partition(vector<int>& nums, int start, int end, int index)
{
	swap(nums[index], nums[end]);
	int l = start - 1;
	for (int i = start; i < end; ++i)
	{
		if (nums[i] <= nums[end])
			swap(nums[++l], nums[i]);
	}
	swap(nums[end], nums[++l]);
	return l;
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.empty())
		return INT_MIN;
	
	int start = 0;
	int end = nums.size() - 1;
	while (k > 0)
	{
		int index = Partition(nums, start, end, start + (end + 1 - start) / 2);
		int left_size = end + 1 - index;
		if (left_size == k)
			return nums[index];
		else if (left_size > k)
		{
			start = index + 1;  
			// Since the size of the subarray from index to the end is bigger than k,
			// you only need to consider the sub-array from the next element of index + 1.
		}
		else
		{
			k -= left_size;
			end = index - 1;
		}
	}
}
