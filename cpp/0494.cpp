/*
    You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
    Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

    Find out how many ways to assign symbols to make sum of integers equal to target S.

    Example 1:
    Input: nums is [1, 1, 1, 1, 1], S is 3. 
    Output: 5
    Explanation: 

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

    There are 5 ways to assign symbols to make the sum of nums be target 3.
    Note:
    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        countSums(nums, nums.size() - 1, S);
        
        return sumCount[S][nums.size() - 1];
    }
    
private:
    int countSums(const vector<int>& nums, int end, int sum)
    {
        if(end == -1)
            return sum == 0;
        
        int count = 0;
        
        int addition = sum + nums[end];
        if(sumCount.find(addition) == sumCount.end() || sumCount[addition].find(end - 1) == sumCount[addition].end())
            sumCount[addition][end - 1] = countSums(nums, end - 1, addition);
        
        count += sumCount[addition][end - 1];
            
        int subtraction = sum - nums[end];
        if(sumCount.find(subtraction) == sumCount.end() || sumCount[subtraction].find(end - 1) == sumCount[subtraction].end())
            sumCount[subtraction][end - 1] = countSums(nums, end - 1, subtraction);
        
        count += sumCount[subtraction][end - 1];
            
        sumCount[sum][end] = count;
        return count;
    }
    
    unordered_map<int, unordered_map<int, int>> sumCount;
};
