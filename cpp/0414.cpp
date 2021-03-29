/*
    Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

    Example 1:
    Input: [3, 2, 1]

    Output: 1

    Explanation: The third maximum is 1.
    Example 2:
    Input: [1, 2]

    Output: 2

    Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
    Example 3:
    Input: [2, 2, 3, 1]

    Output: 1

    Explanation: Note that the third maximum here means the third maximum distinct number.
    Both numbers with value 2 are both considered as second maximum.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int *firstMax = NULL;
        int *secondMax = NULL;
        int *thirdMax = NULL;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(firstMax == NULL || nums[i] > *firstMax)
            {
                delete thirdMax;
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = new int(nums[i]);
            }
            else if(nums[i] == *firstMax)
                continue;
            else if(secondMax == NULL || nums[i] > *secondMax)
            {
                delete thirdMax;
                thirdMax = secondMax;
                secondMax = new int(nums[i]);
            }
            else if(nums[i] == *secondMax)
                continue;
            else if(thirdMax == NULL || nums[i] > *thirdMax)
            {
                delete thirdMax;
                thirdMax = new int(nums[i]);
            }
        }
        
        return thirdMax != NULL ? *thirdMax : *firstMax;
    }
};
