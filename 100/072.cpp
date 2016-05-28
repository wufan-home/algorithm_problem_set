/*
  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
  You have the following 3 operations permitted on a word:
  a) Insert a character
  b) Delete a character
  c) Replace a character

  Solution:
  Use dynamic programming. The minimal distance of the current position is nothing but
  the edit distance of end in the last position, 
  if the the char of two string at the current position are equal;
  the 1 + minimal operations of the above three 
*/


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
			if(word1[i1] == word2[i2])
				dp[i1 + 1][i2 + 1] = dp[i1][i2];
			else
				dp[i1 + 1][i2 + 1] = min(dp[i1][i2] + 1, min(dp[i1 + 1][i2] + 1, dp[i1][i2 + 1] + 1));
		}
	}

	return dp[row][col];
}

