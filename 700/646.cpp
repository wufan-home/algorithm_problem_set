/*
    You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

    Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. 
    Chain of pairs can be formed in this fashion.

    Given a set of pairs, find the length longest chain which can be formed. 
    You needn't use up all the given pairs. You can select pairs in any order.

    Example 1:
    Input: [[1,2], [2,3], [3,4]]
    Output: 2
    Explanation: The longest chain is [1,2] -> [3,4]
    Note:
    The number of given pairs will be in the range [1, 1000].
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() < 2)
            return pairs.size();

        sort(pairs.begin(), pairs.end(), compare);
        
        int maxLen = 1;
        int size = pairs.size();
        vector<int> dp(size);
        dp[0] = 1;
        for(int i = 1; i < size; ++i)
        {
            int localMaxLen = 1;
            for(int j = 0; j < i; ++j)
            {
                if(pairs[j][1] < pairs[i][0])
                    localMaxLen = max(localMaxLen, 1 + dp[j]);
            }
            
            maxLen = max(maxLen, localMaxLen);
            dp[i] = localMaxLen;
        }
        
        return maxLen;
    }
    
private:
    static bool compare(const vector<int>& l, const vector<int>& r)
    {
        return l[0] < r[0] || (l[0] == r[0] && l[1] <= r[1]);
    }
};
