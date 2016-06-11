/*
  Given a string, find the length of the longest substring without repeating characters.
  Examples:
  Given "abcabcbb", the answer is "abc", which the length is 3.
  Given "bbbbb", the answer is "b", with the length of 1.
  Given "pwwkew", the answer is "wke", with the length of 3. 
  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

  Solution: Set two pointers: start - points to the first charater of a candidate substring; 
            end - points to the last of character of the substring.
	    If a substring contains duplicate characters, 
	    any substring of this candidate string whose index of its first character is 
	    before the first duplicate character does not need to consider, 
	    since this substring also contains duplicate characters.
	    
	    When to implement this algorithm, we use a vector to store the index of a character we found
	    and indexed by the integer value of the character we found.
	    All elements of this array are initialized by - 1. 
	    When the value of indexed by the new  character is not -1, it means we found two duplicate charactes.
	    Then, update the start pointer of the substring to the next one of the index of the first character.

	    If the current index is smaller than the start index, it means the last character is not considered.
	    We do not need to update the start pointer.
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
