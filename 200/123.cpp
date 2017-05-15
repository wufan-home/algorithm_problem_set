/*
	Say you have an array for which the ith element is the price of a given stock on day i.

	Design an algorithm to find the maximum profit. You may complete at most two transactions.

	Note:
	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int maxProfitFirstExchange = 0;
        int lowest = prices[0];
        vector<int> firstExchangeMaxProfits(prices.size(), 0);
        for(int i = 1; i < prices.size(); ++i)
        {
            maxProfitFirstExchange = max(maxProfitFirstExchange, prices[i] - lowest);
            firstExchangeMaxProfits[i] = maxProfitFirstExchange;
            lowest = min(lowest, prices[i]);
        }
        
        int maxProfit = 0;
        int highestPrice = prices[prices.size() - 1];
        for(int i = prices.size() - 1; i >= 0; --i)
        {
            if(prices[i] < highestPrice)
                maxProfit = max(maxProfit, highestPrice - prices[i] + (i > 0 ? firstExchangeMaxProfits[i - 1] : 0));
            else
            {
                maxProfit = max(maxProfit, i > 0 ? firstExchangeMaxProfits[i - 1] : 0);
                highestPrice = prices[i];
            }
        }
        
        return maxProfit;
    }
};
