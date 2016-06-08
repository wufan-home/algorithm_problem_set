/*
   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInterleaving(const string& s1, const string& s2, const string& s3)
{
	if(s1.size() + s2.size() != s3.size())
		return false;

	if(s1.empty())
		return s2 == s3;
	else if(s2.empty())
		return s1 == s3;

	int row = s1.size();
	int col = s2.size();
	vector<vector<int> > dp(row + 1, vector<int>(col + 1, -1));

	dp[0][0] = 0;

	for(int i = 0; i < s1.size(); ++i)
	{
		if(s1[i] != s3[i])
		{
			for(int j = i + 1; j <= row; ++j)
				dp[j][0] = 0;
			break;
		}
		dp[i + 1][0] = 1;
	}

	for(int i = 0; i < s2.size(); ++i)
	{
		if(s2[i] != s3[i])
		{
			for(int j = i + 1; j <= col; ++j)
				dp[0][j] = 0;
			break;
		}
		dp[0][i + 1] = 1;
	}

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(dp[i + 1][j + 1] != -1)
				continue;
			cout << i << ": " << s1[i] << ", " << j << ": " << s2[j] << ", " << i + j + 1 << ": " << s3[i + j + 1] << endl;
			if(s1[i] == s3[i + j + 1] && s2[j] == s3[i + j + 1])
				dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j]);
			else if(s1[i] == s3[i + j + 1])
				dp[i + 1][j + 1] = dp[i][j + 1];
			else if(s2[j] == s3[i + j + 1])
				dp[i + 1][j + 1] = dp[i + 1][j];
			else
				dp[i + 1][j + 1] = 0;
		}
	}

	cout << endl;
	for(int i = 0; i <= row; ++i)
	{
		for(int j = 0; j <= col; ++j)
			cout << dp[i][j] << ", ";
		cout << endl;
	}
	
	return dp[row][col];
}

int main()
{
	string s1 = "ef";
	string s2 = "gh";
	string s3 = "ehgf";
	cout << isInterleaving(s1, s2, s3) << endl;
	return 1;
}
