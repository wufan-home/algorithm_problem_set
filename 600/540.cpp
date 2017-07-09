/*
    Given a sorted array consisting of only integers where every element appears twice 
    except for one element which appears once. Find this single element that appears only once.

    Example 1:
    Input: [1,1,2,3,3,4,4,8,8]
    Output: 2
    Example 2:
    Input: [3,3,7,7,10,11,11]
    Output: 10
    Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int l = 0;
        int r = nums.size() - 1;
        for(; l < r;)
        {
            int mid = l + (r - l) / 2;
            //cout << l << " - " << mid << " - " << r << endl;
            if(l < mid && nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
                return nums[mid];
            else if(nums[mid] == nums[mid + 1])
            {
                if((r - mid + 1) % 2 == 1)
                    l = mid + 2;
                else 
                    r = mid - 1;
            }
            else
            {
                if((mid - l + 1) % 2 == 1)
                    r = mid - 2;
                else
                    l = mid + 1;
            }
        }
        
        return nums[l];
    }
};
