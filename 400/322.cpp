// 322.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	if (coins.empty() || amount < coins[0])
		return 0;

	sort(coins.begin(), coins.end());
	vector<int> dp(amount + 1, -1);
	for (int i = 1; i <= amount; ++i)
	{
		if (i < coins[0])
			continue;

		int min_coins = INT_MAX;
		for (int j = 0; j < coins.size() && coins[j] <= i; ++j)
		{
			if (i == coins[j])
			{
				min_coins = 1;
				break;
			}

			if (dp[i - coins[j]] == -1)
				continue;

			min_coins = min(min_coins, dp[i - coins[j]] + 1);
		}

		dp[i] = (min_coins == INT_MAX ? -1 : min_coins);
	}

	return dp[amount];
}

int main()
{
	vector<int> coins({1, 2, 5});
	cout << coinChange(coins, 11) << endl;
    return 0;
}

