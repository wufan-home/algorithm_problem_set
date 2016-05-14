#include <string>
#include <vector>
#include <iostream>

using namespace std;

int minCut(string s) {
        if(s.empty())
		return 0;

	int size = s.size();
	vector<vector<bool> > bPalin(size, vector<bool>(size, false));
	for(int len = 0; len < size; ++len)
	{
		for(int i = 0; i < size - len; ++i)
		{
			bPalin[i][i + len] = (len == 0 ? true :
					      (s[i] == s[i + len] &&
					       (len == 1 ? true : bPalin[i + 1][i + len - 1])));
		}
	}
	
	vector<int> cuts(s.size(), INT_MAX);
	cuts[0] = 0;
	for(int i = 1; i < size; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if(j == 0 && )
		}
	}
	/*
	for(int i = 0; i < size; ++i)
	{
		for(int j = i; j >= 0; --j)
		{
			if(bPalin[j][i])
			{
				if(j == 0)
					cuts[i] = 0;
				else
				{
					if(cuts[j - 1] == 0)
					{
						if(bPalin[0][j - 1])
							cuts[i] = 1;
					}
					else
						cuts[i] = (cuts[i] == 0 ?
							   cuts[j - 1] + 1 :
							   min(cuts[i], cuts[j - 1] + 1));		
				}
			}
		}
	}*/

	return cuts[cuts.size() - 1] == INT_MAX ? 0 : cuts[cuts.size() - 1];
}

int main()
{
	cout << minCut("tabccbabddb") << endl;
	return 1;
}
