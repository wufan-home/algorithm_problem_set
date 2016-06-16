/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.
*/

bool isPalindrome(string s) {
        if(s.empty())
    		return true;
    
    	for(int l = 0, r = s.size() - 1; l <= r;)
    	{
    		if((s[l] < 'A' || s[l] > 'Z') && (s[l] < 'a' || s[l] > 'z') && (s[l] < '0' || s[l] > '9'))
    			++l;
    		else if((s[r] < 'A' || s[r] > 'Z') && (s[r] < 'a' || s[r] > 'z') && (s[r] < '0' || s[r] > '9'))
    			--r;
    		else
    		{
    			if(s[l] >= 'A' && s[l] <= 'Z')
    				s[l] = s[l] - 'A' + 'a';
    
    			if(s[r] >= 'A' && s[r] <= 'Z')
    				s[r] = s[r] - 'A' + 'a';
    
    			if(s[l++] != s[r--])
    				return false;
    		}
    			
    	}
    
    	return true;
}
