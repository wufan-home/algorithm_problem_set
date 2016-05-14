/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s)
{
  int start = 0;
  int end = 0;
  if(s.size() <= 1)
    return 0;

  if(s.size() == 2) {
    if(s[0] == '(' || )
  }
  return 1;
}

int main()
{
  return 1;
}
