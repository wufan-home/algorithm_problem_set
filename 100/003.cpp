/*
  Given a string, find the length of the longest substring without repeating characters.
  Examples:
  Given "abcabcbb", the answer is "abc", which the length is 3.
  Given "bbbbb", the answer is "b", with the length of 1.
  Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int max_len = 0;
	int start = 0;
	vector<int> found(256, -1);
	for(int i = 0; i < s.size(); ++i)
	{
		if(found[s[i]] != -1)
			start = found[s[i]] >= start ? found[s[i]] + 1 : start;

		found[s[i]] = i;
		max_len = max(max_len, i - start + 1);
	}
	return max_len;
}
