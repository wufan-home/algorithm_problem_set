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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::srand(std::time(nullptr));
        int l = 0;
        int r = nums.size();
        int ans = l;
        while (l < r) {
            ans = l;
            swap(nums[l + std::rand() % (r - l)], nums[r - 1]);
            for (int i = l; i < r - 1; ++i) {
                if (nums[i] <= nums[r - 1]) {
                    swap(nums[ans++], nums[i]);
                }
            }
            swap(nums[ans], nums[r - 1]);
            
            if (k == (r - ans <= k ? r - ans : 0)) {
                break;
            }

            if (r - ans <= k) {
                k -= r - ans;
                r = ans;
            }
            else {
                l = ans;
            }
        }
        
        return nums[ans];
    }
};
