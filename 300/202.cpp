/*
  Write an algorithm to determine if a number is "happy".
  A happy number is a number defined by the following process: 
  Starting with any positive integer, replace the number by the sum of the squares of its digits, 
  and repeat the process until the number equals 1 (where it will stay), 
  or it loops endlessly in a cycle which does not include 1. 
  Those numbers for which this process ends in 1 are happy numbers.
  Example: 19 is a happy number
  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1

  Solution:
  If the number contains only one digit, e.g. n = d, the checking function will run
  as d^2 + 0^2.

  It is easy to see that n = 2 .. 6, n is not a happy number.
  Then, we can return false, when the sum of squares is in this range.
*/

class Solution {
public:
    bool isHappy(int n) {
         while(n >= 7)
    	{
    		int sum = 0;
    		for(; n ; n /= 10)
    			sum += (n % 10) * (n % 10);
    		n = sum;
    	}
    
    	return n == 1;
    }
};

class Solution {
public:
    int calculateDigitSquareSum(int num)
    {
        int squareSum = 0;
        for(; num != 0; num /= 10)
            squareSum += (num % 10) * (num % 10);
            
        return squareSum;
    }
    
    bool isHappy(int n) {
        for(; n == 1 || n >= 7; n = calculateDigitSquareSum(n))
        {
            if(n == 1)
                return true;
        }
        
        return false;
    }
};
