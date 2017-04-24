/*
  Implement pow(x, n).

  Solution: The basic idea of the solution is: 
  x^n = ((x^2)^(n/2))(*x when n > 0 or *x^(-1) when n < 0), if n is odd,
        ((x^2)^(n/2)), if n is even.

  Since n/2 = 0 if n = 1 and x^0 = 1, the corner cases of 1 and -1 are covered by the above recursion.

  Since n may be negative, do not use n%2 == 1. This will generate incorrect result because of the mask code.
  The bit-operation has more scenarioes to apply.
*/

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0)
            return 1;
            
        if(x == 0 || x == 1 || n == 1)
            return x;
            
        if(n & 1 == 1)
            return (n < 0 ? 1 / x : x) * myPow(x * x, n / 2);
        else
            return myPow(x * x, n / 2);
    }
};
