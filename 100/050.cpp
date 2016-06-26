/*
  Implement pow(x, n).

  Solution: The basic idea of the solution is: 
  x^n = ((x^2)^(n/2))(*x when n > 0 or *x^(-1) when n < 0), if n is odd,
        ((x^2)^(n/2)), if n is even.

  Since n/2 = 0 if n = 1 and x^0 = 1, the corner cases of 1 and -1 are covered by the above recursion.

  Since n may be negative, do not use n%2 == 1. This will generate incorrect result because of the mask code.
  The bit-operation has more scenarioes to apply.
*/

double myPow(double x, int n)
{
    	if(x == 0)
    		return 0;
    	
    	if(n == 0)
    		return 1;
        else if (n & 1 == 1) //Since n may be negative, do not use n%2 == 1.
    		return myPow(x * x, (n + (n < 0 ? 1 : -1)) / 2) * (n > 0 ? x : 1/x);
    	else
    		return myPow(x * x, n / 2);
}
