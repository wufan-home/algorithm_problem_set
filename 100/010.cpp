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

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isMatch(const string& s, const string& p) {
	if(s.empty())
		return true;

	bool result = false;
	for(int pi = 0; pi < p.size(); ++pi)
	{
		if(result)
			break;

		if(p[pi] == '*')
			continue;
		if(p[pi] == '.')
			result = isMatch(s.substr(1), p.substr(pi + 1));
		else if(s[0] == p[pi])
		{
			if(s.size() > 1 && s[1] == '*')
			{
				
			}
		}
			
	}
	
	return result;
}

int main()
{
  cout << "s = " << "a" << ", p = " << "aa" << ": "
       << (isMatch("a", "aa") ? "Match!" : "Dismatch!") << endl; //Expected: match.
  
  cout << "s = " << "aa" << ", p = " << "a" << ": "
       << (isMatch("aa", "a") ? "Match!" : "Dismatch!") << endl; //Expected: Dismatch.

  cout << "s = " << "aa" << ", p = " << "baa" << ": "
       << (isMatch("aa", "baa") ? "Match!" : "Dismatch!") << endl; //Expected: Match.

  cout << "s = " << "aa" << ", p = " << "aa" << ": "
       << (isMatch("aa", "aa") ? "Match!" : "Dismatch!") << endl; //Expected: Match.

  cout << "s = " << "aa" << ", p = " << ".a" << ": "
       << (isMatch("aa", ".a") ? "Match!" : "Dismatch!") << endl; //Expected: Match.

  cout << "s = " << "aa" << ", p = " << ".." << ": "
       << (isMatch("aa", "..") ? "Match!" : "Dismatch!") << endl; //Expected: Match.

  cout << "s = " << "aa" << ", p = " << "b." << ": "
       << (isMatch("aa", "b.") ? "Match!" : "Dismatch!") << endl; //Expected: Dis.

  cout << "s = " << "aa" << ", p = " << ".b" << ": "
       << (isMatch("aa", ".b") ? "Match!" : "Dismatch!") << endl; //Expected: Dis.

  /*
  cout << "s = " << "aa" << ", p = " << "a." << ": "
       << (isMatch("aa", "a*") ? "Match!" : "Dismatch!") << endl; //Expected: match.
  
  cout << "s = " << "aa" << ", p = " << "a*" << ": "
       << (isMatch("aa", "a*") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "aa" << ", p = " << ".*" << ": "
       << (isMatch("aa", ".*") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "a" << ", p = " << "a*" << ": "
       << (isMatch("a", "a*") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "abc" << ", p = " << "a*c" << ": "
       << (isMatch("abc", "a*c") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "abc" << ", p = " << "a.c" << ": "
       << (isMatch("abc", "a.c") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "abc" << ", p = " << "a.*c" << ": "
       << (isMatch("abc", "a.*c") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "abc" << ", p = " << "a*.c" << ": "
       << (isMatch("abc", "a*.c") ? "Match!" : "Dismatch!") << endl; //Expected: match.

  cout << "s = " << "b" << ", p = " << "a*" << ": "
       << (isMatch("b", "a*") ? "Match!" : "Dismatch!") << endl; //Expected: Dismatch.

  cout << "s = " << "b" << ", p = " << "*" << ": "
       << (isMatch("b", "*") ? "Match!" : "Dismatch!") << endl; //Expected: Dismatch.
  */
  return 1;
}
