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

bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 + len2 != s3.size())
		return false;
        if(len1 == 0)
		return s3 == s2;
        if(len2 == 0)
		return s3 == s1;
	
        vector<vector<int> > aux(len1 + 1, vector<int>(len2 + 1, 0));
        aux[0][0] = 1;
        for(int i = 1; i <= len1; ++i)
		aux[i][0] = ((s1[i - 1] == s3[i - 1]) & aux[i - 1][0]);
        
        for(int j = 1; j <= len2; ++j)
		aux[0][j] = ((s2[j - 1] == s3[j - 1]) & aux[0][j - 1]);
        
        for(int i = 1; i <= len1; ++i)
        {
		for(int j = 1; j <= len2; ++j)
		{
			if(s3[i + j - 1] == s1[i - 1])
				aux[i][j] = aux[i - 1][j];
			if(s3[i + j - 1] == s2[j - 1])
				aux[i][j] |= aux[i][j - 1];
		}
        }
	
        return aux[len1][len2];
}

int main()
{
	string s1 = "ef";
	string s2 = "gh";
	string s3 = "ehgf";
	cout << isInterleaving(s1, s2, s3) << endl;
	return 1;
}
