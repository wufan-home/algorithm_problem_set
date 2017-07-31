/*
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
    Example:

    prices = [1, 2, 3, 0, 2]
    maxProfit = 3
    transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int maxProfit = 0;
        
        int size = prices.size();
        vector<int> buys(size, 0);
        vector<int> sells(size, 0);
        vector<int> idles(size, 0);
        
        buys[0] = -prices[0];
        
        for(int i = 1; i < size; ++i)
        {
            buys[i] = max(idles[i - 1] - prices[i], buys[i - 1]);
            sells[i] = max(buys[i - 1] + prices[i], sells[i - 1]);
            idles[i] = max(idles[i - 1], max(buys[i - 1], sells[i - 1]));
            
            maxProfit = max(maxProfit, sells[i]);
        }
        
        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int maxProfit = 0;
        
        int size = prices.size();
        
        int preBuy = 0;
        int buy = INT_MIN;
        
        int sell = 0;
        int preSell = 0;
        
        int idle = 0;
        int preIdle = 0;
        
        for(int i = 0; i < size; ++i)
        {
            preBuy = buy;
            preSell = sell;
            preIdle = idle;
            
            buy = max(idle - prices[i], preBuy);
            sell = max(preBuy + prices[i], preSell);
            idle = max(preIdle, max(preBuy, preSell));
            
            maxProfit = max(maxProfit, sell);
        }
        
        return maxProfit;
    }
};
