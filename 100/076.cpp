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

class Solution {
public:
	string minWindow(string s, string t) {
		const int ss = s.size();
		const int ts = t.size();

		if (ts == 0 || ss < ts)
			return "";

		unordered_map<char, int> frequency;
		unordered_map<char, int> count;
		for (int i = 0; i < t.size(); ++i)
		{
			if (frequency.find(t[i]) == frequency.end())
			{
				frequency[t[i]] = 0;
				count[t[i]] = 0;
			}

			++frequency[t[i]];
		}

		int minWindowLength = INT_MAX;
		int finalStart = 0;
		for (int start = 0, end = 0; end < s.size(); ++end)
		{
			if (frequency.find(s[end]) == frequency.end())
				continue;

			++count[s[end]];
			if (!isCountLargerOrEqualToFrequency(count, frequency))
				continue;

			for (; isCountLargerOrEqualToFrequency(count, frequency); ++start)
			{
				if (count.find(s[start]) != count.end())
					--count[s[start]];
			}
			++count[s[--start]];

			if (end - start + 1 < minWindowLength)
			{
				minWindowLength = end - start + 1;
				finalStart = start;
			}

			--count[s[start++]];
		}

		return minWindowLength == INT_MAX ? "" : s.substr(finalStart, minWindowLength);
	}

private:
	bool isCountLargerOrEqualToFrequency(unordered_map<char, int>& count, unordered_map<char, int>& frequency)
	{
		for (unordered_map<char, int>::iterator itFreq = frequency.begin(), itCount = count.begin();
			itFreq != frequency.end();
			++itFreq, ++itCount)
		{
			if (itCount->second < itFreq->second)
				return false;
		}
		return true;
	}
};
