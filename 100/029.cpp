/*
  Divide two integers without using multiplication, 
  division and mod operator.
  If it is overflow, return MAX_INT.

  Solution: From 
  dividend = divisor * b 
           = divisor * (b_{n} * 2^{n} + b_{n - 1} * 2^{n - 1} + ... + b_{0} * 2^{0})
	   = divisor * b_{n} * 2^{n} + divisor * b_{n - 1} * 2^{n - 1} + ... + divisor * b_{0} * 2^{0}
  we have b is obtained by adding values of all shifting divisor left to n digits.  
*/

int divide(int dividend, int divisor)
{
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;
        if(dividend == 0 || divisor == 1)
		return dividend;
        
        bool neg = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
        long long u = labs(dividend);
        long long l = labs(divisor);
        int result = 0;
        while(u >= l)
        {
		long long temp = l;
		long long multiple = 1;
		for(; (temp << 1) <= u; multiple <<= 1, temp <<= 1) {}
		result += multiple;
		u -= temp;
        }
        
        return (neg ? -1 : 1) * result; 
}
