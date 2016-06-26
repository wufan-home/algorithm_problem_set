/*
  Implement pow(x, n).

  Solution: The basic idea of the solution is: x^n = ((x^2)^(n/2))(*x when n > 0 or *x^(-1) when n < 0).
*/

double myPow(double x, int n)
{
    	if(x == 0)
    		return 0;
    	
    	if(n == 0)
    		return 1;
        else if (n & 1 == 1)
    		return myPow(x * x, (n + (n < 0 ? 1 : -1)) / 2) * (n > 0 ? x : 1/x);
    	else
    		return myPow(x * x, n / 2);
}
