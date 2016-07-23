/*
  Find the kth largest element in an unsorted array. 
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  For example,
  Given [3,2,1,5,6,4] and k = 2, return 5.
  Note: 
  You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

int findKthLargest(vector<int>& nums, int k) {
    	int s = 0;
    	int e = nums.size() - 1;
    	while(s < e)
    	{
    		swap(nums[s + (e + 1 - s) / 2], nums[e]);
    		int l = s - 1;
    		for(int i = s; i < e; ++i)
    		{
    			if(nums[i] > nums[e])
    				swap(nums[++l], nums[i]);
    		}
    		swap(nums[++l], nums[e]);
    		if(l > k - 1)
			e = l - 1;
    		else if((s = min(k - 1, l + 1)) == k - 1)
    		        break;
    	}
    	return nums[s];
}
