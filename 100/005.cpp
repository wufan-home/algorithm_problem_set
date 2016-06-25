/*
	Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, 
	and there exists one unique longest palindromic substring.
*/

string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
            
        int start = 0;
        int max_len = 1;
        for(int i = 0; i < s.size() - max_len / 2; )
        {
            int l = i;
            int r = i;
            for(; r < s.size() - 1 && s[r + 1] == s[r]; ++r) {}
            i = r + 1;
            for(; l > 0 && r < s.size() - 1 && s[l - 1] == s[r + 1]; --l, ++r) {}
            if(r - l + 1 > max_len)
            {
                max_len = r - l + 1;
                start = l;
            }
        }

        return s.substr(start, max_len);
}
