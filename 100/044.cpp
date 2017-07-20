/*
  Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution
{
public:
    bool isMatch(const string& s, const string& p)
    {
	int pLen = p.size();
	int sLen = s.size();
	int pcur = 0;
	int scur = 0;
	int pstar = -1;
	int sstar = -1;
	while(scur < sLen)
	{
	    if(s[scur] == p[pcur] || p[pcur] == '?')
	    {
		++scur;
		++pcur;
	    }
	    else if(p[pcur] == '*')
	    {
		pstar = pcur++;
		sstar = scur;
	    }
	    else if(pstar > -1)
	    {
		pcur = pstar + 1;
		scur = ++sstar;
	    }
	    else
		return false;
	}

	if(pcur == pLen - 1 && p[pcur] == '*') ++pcur;

	return pcur == pLen;
    }
};
