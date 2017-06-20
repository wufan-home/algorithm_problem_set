/*
  Given a string, determine if a permutation of the string could form a palindrome.

  For example,
  "code" -> False, "aab" -> True, "carerac" -> True.
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> charCount(256, 0);
        
        for(int i = 0; i < s.size(); ++i)
            ++charCount[s[i]];
            
        int oddNumCount = 0;
        for(int i = 0; i < 256; ++i)
            oddNumCount += charCount[i] % 2;
            
        return (s.size() % 2 == 0 && oddNumCount == 0) ||
            (s.size() % 2 == 1 && oddNumCount == 1);
    }
};
