/*
     On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

    Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

    Example 1:

    Input: cost = [10, 15, 20]
    Output: 15
    Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

    Example 2:

    Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    Output: 6
    Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

    Note:

        cost will have a length in the range [2, 1000].
        Every cost[i] will be an integer in the range [0, 999].

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> totalCost(cost.size(), 0);
        dp(cost, cost.size() - 1, totalCost);
        return totalCost[cost.size() - 1];
    }
    
private:
    int dp(vector<int>& cost, int end, vector<int>& totalCost) {
        if (end == 0 || end == 1) {
            return 0;
        }
        
        if (totalCost[end] != 0) {
            return totalCost[end];
        }
        
        totalCost[end] = min(cost[end - 1] + dp(cost, end - 1, totalCost), cost[end - 2] + dp(cost, end - 2, totalCost));
        return totalCost[end];
    }
};
