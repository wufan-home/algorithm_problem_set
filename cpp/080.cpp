/*
	Follow up for "Remove Duplicates":
	What if duplicates are allowed at most twice?

	For example,
	Given sorted array nums = [1,1,1,2,2,3],

	Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
	It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
            
        int write = 0;
        for(int read = 1; read < nums.size(); ++read)
        {
            if(nums[read] > nums[write])
                nums[++write] = nums[read];
            else if(nums[read] == nums[write])
            {
                if(read == 1 || nums[write] > nums[write - 1])
                    nums[++write] = nums[read];
            }
        }
        
        return write + 1;
    }
};
