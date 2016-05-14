/*
  Given a string, determine if a permutation of the string could form a palindrome.

  For example,
  "code" -> False, "aab" -> True, "carerac" -> True.
*/

class Solution {
public:
	bool canPermutePalindrome(string s)
	{
		if(s.size() <= 1)
			return true;

		int size = s.size();
		int count[256];
		memset(count, 256, 0);
		for(int i = 0; i < size; ++i)
		{
			if(++count[s[i]] == 3)
				return false;
		}

		int count1 = 0;
		for(int i = 0; i < 256; ++i)
		{
			if(count[i] == 1)
				++count1;
		}

		return ((size & 0) ? count1 == 0 : count1 == 1);
	}
}
