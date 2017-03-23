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

int lengthOfLongestSubstring(string s) 
    {
        int max_length = 0;
        vector<int> char_to_index(256, -1);
        for(int start = 0, end = 0; end < s.size(); ++end)
        {
            const int alphabet_index = (int)s[end];
            if(char_to_index[alphabet_index] >= start)
                start = char_to_index[alphabet_index] + 1;
            char_to_index[alphabet_index] = end;
            max_length = max(max_length, end - start + 1);
        }
        
        return max_length;
    }
