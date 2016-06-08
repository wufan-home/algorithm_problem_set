/*
   Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

   For example,
   S = "ADOBECODEBANC"
   T = "ABC"

   Minimum window is "BANC".

   Note:
   If there is no such window in S that covers all characters in T, return the empty string "".

   If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef map<char, int>::iterator IT;

char FindMissingChar(map<char, int>& current, map<char, int>& total)
{
	char missing = '\0';
	for(IT c = current.begin(), t = total.begin();
	    c != current.end() && t != total.end(); ++c, ++t)
	{
		if(c->second < t->second)
		{
			missing = c->first;
			break;
		}
	}
	return missing;
}

string minWindow(string s, string t) {
        if(s.empty() || s.size() < t.size())
		return "";
	
	int ssize = s.size();
	int tsize = t.size();
	map<char, int> total;
	map<char, int> current;
	vector<bool> existed(128, false);
	for(int i = 0; i < tsize; ++i)
	{
		if(total.find(t[i]) == total.end())
		{
			total[t[i]] = 1;
			current[t[i]] = 0;
			existed[t[i]] = true;
		}
		else
			++total[t[i]];
	}

	int l = 0;
	for(; l < ssize; ++l)
	{
		if(existed[s[l]])
			break;
	}
	if(l == ssize)
		return "";

	int start = l;
	int end = l;
	char last_less = '\0';
	for(int r = l; r < ssize; ++r)
	{
		if(!existed[s[r]])
			continue;

		++current[s[r]];
    
		if(current[s[r]] < total[s[r]] ||
		   (last_less != '\0' && current[last_less] < total[last_less]) ||
		   (last_less = FindMissingChar(current, total)) != '\0')
			continue;

		if(start == end || r - l < end - start)
		{
			start = l;
			end = r;
		}

		while(1)
		{
			if(start == end || r - l < end - start)
			{
				start = l;
				end = r;
			}

			++l;
			if(!existed[s[l - 1]])
				continue;

			--current[s[l - 1]];
			if(current[s[l - 1]] < total[s[l - 1]])
				break;
		}
	}

	if(start == end && tsize > 1)
		return "";
	return s.substr(start, end - start + 1);
}

int main()
{
	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
	cout << minWindow("aa", "aa") << endl;
	cout << minWindow("cabwefgewcwaefgcf", "cae") << endl;
	cout << minWindow("babb", "baba") << endl;
	cout << minWindow("a", "a") << endl;
	return 1;
}
