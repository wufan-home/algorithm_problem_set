/*
  
 */

class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> results;
		if(s.size() < 2)
			return results;

		for(int i = 0; i < s.size() - 1; ++i)
		{
			if(s[i] == '+' && s[i + 1] == '+')
			{
				results.push_back(s);
				*(results.end() - 1)[i] = '-';
				*(results.end() - 1)[i + 1] = '-';
			}
		}

		return results;
	}
}
