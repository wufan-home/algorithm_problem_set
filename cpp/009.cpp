/*
  Determine whether an integer is a palindrome. Do this without extra space.
  Could negative integers be palindromes? (ie, -1)
  If you are thinking of converting the integer to string, 
  note the restriction of using extra space.
  You could also try reversing an integer. 
  However, if you have solved the problem "Reverse Integer", 
  you know that the reversed integer might overflow. How would you handle such case?
  There is a more generic way of solving this problem.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int div = 1;
        while(x / 10 >= div)
            div *= 10;
        
        while(div > 1)
        {
            int first = x / div;
            int last = x % 10;
            if(first != last)
                return false;
            
            x %= div;
            x /= 10;
            div /= 100;
        }
        
        return true;
    }
};
