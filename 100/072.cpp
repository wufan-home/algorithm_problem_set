#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
	if(word1.empty())
		return word2.size();

	if(word2.empty())
		return word1.size();

	int row = word1.size();
	int col = word2.size();
	vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));

	for(int i = 1; i <= col; ++i)
		dp[0][i] = i;

	for(int i = 1; i <= row; ++i)
		dp[i][0] = i;

	for(int i1 = 0; i1 < row; ++i1)
	{
		for(int i2 = 0; i2 < col; ++i2)
		{
			cout << i1 << " - " << word1[i1] << ", " << i2 << " - " << word2[i2] << endl;
			if(word1[i1] == word2[i2])
				dp[i1 + 1][i2 + 1] = dp[i1][i2];
			else
				dp[i1 + 1][i2 + 1] = min(dp[i1][i2] + 1, min(dp[i1 + 1][i2] + 1, dp[i1][i2 + 1] + 1));
		}
	}

	for(int i = 0; i <= row; ++i)
	{
		for(int j = 0; j <= col; ++j)
		{
			cout << dp[i][j] << ",";
		}
		cout << endl;
	}
	
	return dp[row][col];
}

int main()
{
  string word1 = "abcdefg";  //7
  string word2 = "bdf";  //3

  cout << minDistance(word1, word2) << endl;
}
