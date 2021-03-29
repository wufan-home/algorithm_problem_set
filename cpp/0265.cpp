/*
    There are a row of n houses, each house can be painted with one of the k colors. 
    The cost of painting each house with a certain color is different. 
    You have to paint all the houses such that no two adjacent houses have the same color.

    The cost of painting each house with a certain color is represented by a n x k cost matrix. 
    For example, costs[0][0] is the cost of painting house 0 with color 0; 
    costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

    Note:
    All costs are positive integers.

    Follow up:
    Could you solve it in O(nk) runtime?
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty())
            return 0;
        
        int min1 = 0;
        int min2 = 0;
        int last = -1;
        for(int i = 0; i < costs.size(); ++i)
        {
            int m1 = INT_MAX;
            int m2 = INT_MAX;
            int cur = -1;
            for(int j = 0; j < costs[i].size(); ++j)
            {
                int cost = costs[i][j] + (j == last ? min2 : min1);
                if(cost < m1)
                {
                    m2 = m1;
                    m1 = cost;
                    cur = j;
                }
                else if(cost < m2)
                {
                    m2 = cost;
                }
            }
            
            min1 = m1; min2 = m2; last = cur;
        }
        
        return min1;
    }
};
