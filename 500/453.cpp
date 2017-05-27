/*
    Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

    You may assume the array's length is at most 10,000.

    Example:

    Input:
    [1,2,3]

    Output:
    2

    Explanation:
    Only two moves are needed (remember each move increments or decrements one element):

    [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
            
        int minValue = nums[0];
        int steps = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            minValue = min(minValue, nums[i]);
            steps += nums[i] - nums[0];
        }
        
        steps += (nums[0] - minValue) * (nums.size() - 1);
        
        return steps;
    }
};
