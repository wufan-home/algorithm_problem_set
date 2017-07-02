/*
    There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
    The cost of painting each house with a certain color is different. 
    You have to paint all the houses such that no two adjacent houses have the same color.

    The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
    For example, costs[0][0] is the cost of painting house 0 with color red; 
    costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

    Note:
    All costs are positive integers.
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())
            return 0;
        
        vector<vector<int>> minCosts(costs.size(), vector<int>(3, 0));
        minCosts[0] = costs[0];
        int size = costs.size();
        for(int i = 1; i < size; ++i)
        {
            minCosts[i][0] = costs[i][0] + min(minCosts[i - 1][1], minCosts[i - 1][2]);
            minCosts[i][1] = costs[i][1] + min(minCosts[i - 1][0], minCosts[i - 1][2]);
            minCosts[i][2] = costs[i][2] + min(minCosts[i - 1][0], minCosts[i - 1][1]);
        }
        
        return min(minCosts[size - 1][0], min(minCosts[size - 1][1], minCosts[size - 1][2]));
    }
};
