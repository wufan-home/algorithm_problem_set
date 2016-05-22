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
#include <unordered_map>
#include <unordered_set>

using namespace std;

string minWindow(const string &source, const string &target)
{
        if(source.empty() && target.empty())
            return "";

	unordered_map<char, int> hash;
	unordered_set<char> more;
	unordered_map<char, int> cached;
	for(int i = 0; i < target.size(); ++i)
	{
		char c = target[i];
		if(hash.find(c) == hash.end())
		{
			hash[c] = 0;
			cached[c] = 0;
			more.insert(target[i]);
		}
		++hash[target[i]];
	}
	
	
        string result("");
	for(int back = 0, front = 0; front < source.size(); ++front)
	{
		char c = source[front];
		if(cached.find(c) != cached.end())
		{
			++cached[c];
			if(cached[c] >= hash[c])
				more.erase(c);
		}

		for(;back <= front && more.empty(); ++back)
		{
			if(result.empty() || front - back + 1 < result.size())
				result = source.substr(back, front - back + 1);

			char c = source[back];
			if(hash.find(c) != hash.end())
			{
				if(--cached[c] < hash[c])
					more.insert(c);
			}
		}
	}
	
        return result;
}


int main()
{
	cout << "abcde, " << "db: "<< minWindow("abcde", "db") << endl;
	cout << "ADOBECODEBANC, " << "ABC:"<< minWindow("ADOBECODEBANC", "ABC") << endl;
	cout << "aa, " << "aa: "<< minWindow("aa", "aa") << endl;
	cout << "cabwefgewcwaefgcf, " << "cae: " << minWindow("cabwefgewcwaefgcf", "cae") << endl;
	cout << "babb, " << "baba: " << minWindow("babb", "baba") << endl;
	cout << "a, " << "a: "<< minWindow("a", "a") << endl;
	return 1;
}
