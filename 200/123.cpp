#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if(prices.empty())
		return 0;

	vector<int> max_profits_left(prices.size(), 0);
	int min_price = prices[0];
	for(int i = 1; i < prices.size(); ++i)
	{
		if(prices[i] - min_price > max_profits_left[i - 1])
			max_profits_left[i] = prices[i] - min_price;
		else
			max_profits_left[i] = max_profits_left[i - 1];

		if(prices[i] < min_price)
			min_price = prices[i];
	}

	int max_profit = 0;
	int max_price = *(prices.end() - 1);
	int max_profit_right = 0;
	for(int i = prices.size() - 2; i >= 0; --i)
	{
		if(max_price - prices[i] > max_profit_right)
		{
			max_profit_right = max_price - prices[i];
			if(max_profit_right + max_profits_left[i] > max_profit)
				max_profit = max_profit_right + max_profits_left[i];
		}

		if(prices[i] > max_price)
			max_price = prices[i];
	}

	return max_profit;
}
