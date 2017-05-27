/*
    Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

    Example:

    Input:
    [1,2,3]

    Output:
    3

    Explanation:
    Only three moves are needed (remember each move increments two elements):

    [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
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
