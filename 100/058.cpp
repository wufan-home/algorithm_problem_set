/*
  Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

  If the last word does not exist, return 0.

  Note: A word is defined as a character sequence consists of non-space characters only.

  For example,
  Given s = "Hello World",
  return 5. 
*/

#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	s.push_back(' ');
	int result = 0;
	int len = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == ' ')
		{
			result = len != 0 ? len : result;
			len = 0;
		}
		else
			++len;
	}

	return result;
}

