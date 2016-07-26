/*
  Given a string which contains only lowercase letters, 
  remove duplicate letters so that every letter appear once and only once. 
  You must make sure your result is the smallest in lexicographical order among all possible results.
  Example:
  Given "bcabc"
  Return "abc"
  Given "cbacdcbc"
  Return "acdb"

  Solution: The basic process is to compare all candidate substring from the first character.
  Since the problem requires every distinct characters must exist in a candidate,
  the comparison happens only for the ones whose counts of every distinct characters are not zero.
  Take the least character as the current character 
  and recursively apply the process to the string without the selected charater.
*/

string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
    	int first = 0;
    	for(int i = 0; i < s.size(); ++count[s[i++] - 'a']) {}
    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(s[i] < s[first])
    			first = i;
    		if(--count[s[i] - 'a'] == 0)
    			break;
    	}
    	for(int i = first + 1; i < s.size();)
    	{
    		if(s[i] == s[first])
    			s.erase(s.begin() + i);
    		else
    			++i;
    	}
    
    	if(s.empty())
    		return"";
    	else
    	{
    		string result(1, s[first]);
    		result.append(removeDuplicateLetters(s.substr(first + 1)));
    		return result;
    	}
}
