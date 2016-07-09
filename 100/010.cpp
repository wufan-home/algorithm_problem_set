/*
  Implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)

  Some examples:
  isMatch("aa","a") → false
  isMatch("aa","aa") → true
  isMatch("aaa","aa") → false
  isMatch("aa", "a*") → true
  isMatch("aa", ".*") → true
  isMatch("ab", ".*") → true
  isMatch("aab", "c*a*b") → true
*/

bool helper(const string& s, int si, const string& p, int pi)
{
    	if(si == s.size())
    		return pi == p.size() || (pi < p.size() - 1 && p[pi + 1] == '*' && helper(s, si, p, pi + 2));
    	else
    	{
    		if(pi == p.size() - 1)
    			return (p[pi] == s[si] || p[pi] == '.') && si == s.size() - 1;
    		else
    		{
    			if(p[pi + 1] == '*')
    				return ((p[pi] == s[si] || p[pi] == '.') &&
    					helper(s, si + 1, p, pi)) || helper(s, si, p, pi + 2);
    			else
    				return (p[pi] == s[si] || p[pi] == '.') &&
    					helper(s, si + 1, p, pi + 1);
    		}
    	}
}

bool isMatch(const string& s, const string& p)
{
    	return helper(s, 0, p, 0);
}
