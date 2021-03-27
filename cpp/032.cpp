/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 * Solution: This is a dynamic-programming method. 
 * Any candidate string is nothing but a combination of longest sub-parentheses-strings starting from a '(',
 * where there is no invalid '(' or ')' between any two such substrings.
 * We use a vector to store the maximal length from a '(' (the also put this length to its matched ')').
 * 
 */

int longestValidParentheses(string s) {
        vector<int> match(s.size(), 0);
        for(int i = 1; i < s.size(); ++i)
        {
		if(s[i] == ')')
		{
			if(s[i - 1] == '(')
			{
				match[i - 1] = 2;
				match[i] = 2;
			}
			else if(match[i - 1])
			{
				int j = i - 1;
				for( ;j >= 0 && match[j]; j -= match[j]) {}
				if(j >= 0 && s[j] == '(')
				{
					match[i] = i - j + 1;
					match[j] = i - j + 1;
				}
			}
		}
        }
        
        int max_len = 0;
        int len = 0;
        for(int i = 0; i < match.size();)
        {
		if(match[i] == 0)
		{
			++i;
			len = 0;
		}
		else
		{
			len += match[i];
			max_len = max(max_len, len);
			i += match[i];
		}
        }
        
        return max_len;
}
