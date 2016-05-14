/*
   Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" 
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare(const string& l, const string& r)
{
	// We do not need to consider the case that l == r;
	// l.size() == r.size();
	int size = l.size();
	for(int i = 0; i < size; ++i)
	{
		if(l[i] < r[i])
			return true;
		else if(l[i] > r[i])
			return false;
	}
}

string FormNewString(string& old, char new_char)
{
	string new_string;
	string::iterator it_old = find(old.begin(), old.end(), new_char);
	for(string::iterator it_new = old.begin(); it_new != old.end(); ++it_new)
	{
		if(it_new == it_old)
			continue;

		new_string.push_back(*it_new);
	}

	new_string.push_back(new_char);
	return new_string;
}

string removeDuplicateLetters(string s)
{
        if(s.empty())
		return false;

	int size = s.size();
	bool existed[26];
	memset(existed, false, 26);
	for(int i = 0; i < size; ++i)
		existed[s[i] - 'a'] = true;

	int num_diff_char = 0;
	for(int i = 0; i < 26; ++i)
	{
		if(existed[i])
			++num_diff_char;
	}

	vector<string> leasts(num_diff_char, "");
	leasts[0] = s.substr(0, 1);
	for(int i = 1; i < s.size(); ++i)
	{
		for(int j = num_diff_char - 1; j > 0; --j)
		{
			if(leasts[j].empty())
			{
				if(!leasts[j - 1].empty())
				{
					string new_str = FormNewString(leasts[j - 1], s[i]);
					if(new_str.size() > leasts[j - 1].size())
						leasts[j] = new_str;
				}
			}
			else
			{
				string new_str_last = FormNewString(leasts[j - 1], s[i]);
				string new_str_current = FormNewString(leasts[j], s[i]);
				if(new_str_last.size() == leasts[j].size() && Compare(new_str_last, leasts[j]))
					leasts[j] = new_str_last;
				if(new_str_current.size() == leasts[j].size() && Compare(new_str_current, leasts[j]))
					leasts[j] = new_str_current;
			}
		}

		if(s[i] < leasts[0][0])
			leasts[0][0] = s[i];
	}

	return *(leasts.end() - 1);
}


int main()
{
	cout << removeDuplicateLetters("cbacdcbc") << endl;
	cout << removeDuplicateLetters("bcabc") << endl;
	return 1;
}
