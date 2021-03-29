/*
    Find all possible combinations of k numbers that add up to a number n, 
    given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


    Example 1:

    Input: k = 3, n = 7

    Output:

    [[1,2,4]]

    Example 2:

    Input: k = 3, n = 9

    Output:

    [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        getSum(k, n, 9, cur);
        return res;
    }
    
private:
    void getSum(int k, int n, int end, vector<int>& cur)
    {
        if(k == 0)
        {
            if(n == 0)
                res.push_back(cur);

            return;
        }
        
        for(int i = end; i >= 1; --i)
        {
            if(i > n)
                continue;
            
            cur.push_back(i);
            getSum(k - 1, n - i, i - 1, cur);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> res;
};
