//

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
