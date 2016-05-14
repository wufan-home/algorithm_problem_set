
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k == 0)
		return 0;

	int size = prices.size();
	vector<vector<int> > dp(k, vector<int>(prices.size(), 0));
	for(int i = 0; i < k; ++i)
	{
		if(i == 0)
		{
			int min_price;
			for(int j = 0; j < size; ++i)
			{
				if(prices[j] )
			}
		}
		else
		{}
	}

	return dp[k - 1][prices.size() - 1];
}
