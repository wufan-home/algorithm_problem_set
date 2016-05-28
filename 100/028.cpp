/*
  Implement strStr().
  Returns the index of the first occurrence of needle in haystack, 
  or -1 if needle is not part of haystack.

  Solution:
  1. Brute force method.
 */

int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
    		return -1;
    
            if(haystack.empty() || needle.empty())
    		return 0;
    
    	for(int i = 0; i < haystack.size() - needle.size() + 1; ++i)
    	{
    		int j = 0;
    		for(; j < needle.size(); ++j)
    		{
    			if(haystack[i + j] != needle[j])
    				break;
    		}
    		if(j == needle.size())
    			return i;
    	}
    	return -1;
}
