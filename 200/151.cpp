#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s) {
        if(s.empty())
		return;

	int start = 0;
	for(; start < s.size() && s[start] == ' '; ++start) {}
	if(start == s.size())
	{
		s = "";
		return;
	}

	int end = s.size() - 1;
	for(; end > start && s[end] == ' '; --end) {}

	s = s.substr(start, end - start + 1);
	for(int i = 0; i < s.size();)
	{
		if(s[i] != ' ')
		{
			int j = i + 1;
			for(; j < s.size() && s[j] != ' '; ++j) {}
			for(int start = i, end = j - 1; start < end; ++start, --end)
				swap(s[start], s[end]);
			i = j;
		}
		else
		{
			++i;
			if(s[i] == ' ')
			{
				for(; i < s.size() && s[i] == ' ';)
					s.erase(s.begin() + i);
			}
		}
	}

	for(int l = 0, r = s.size() - 1; l < r; ++l, --r)
		swap(s[l], s[r]);
}

int main()
{
	string s("  the     sky         is    blue             ");
	reverseWords(s);
	cout << s << endl;
	return 1;
}
