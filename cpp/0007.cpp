/*
  Reverse digits of an integer.
  Example1: x = 123, return 321
  Example2: x = -123, return -321

  Have you thought about this?
  Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
  If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
  Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
  then the reverse of 1000000003 overflows. How should you handle such cases?
  For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
  Update (2014-11-10):
  Test cases had been added to test the overflow behavior.

  Solution: For such problems, we first remove the sign if needed.
*/

int reverse(int x) 
{
	// This method avoid using long long.
	// Then, it is a more generic method than that with long long. (machine independent)
	if(x == 0 || x == INT_MAX || x == INT_MIN) // INT_MAX and INT_MIN cannot be reversed.
	    	return 0;

	const int positive = (int)abs(x);
	const bool sign = x > 0;

	const int reverse = 0;
	const int bound = INT_MAX / 10;
	while(positive)
	{
		const int candidate = reverse * 10;
		const int addin = positive % 10;
		if(reverse > bound || INT_MAX - candidate < addin) // Use substraction to avoid overflow.
			return 0;

		reverse = candidate + addin;
		positive /= 10;
	}

	return (sign ? 1 : -1) * reverse;
}

int reverse(int x) {
	long long rv = 0;
	bool neg = (x < 0);
	long long abx = (neg ? -1 : 1) * static_cast<long long>(x);
	for(; abx; abx /= 10)
	{
		rv = rv * 10 + abx % 10;
		if((neg && rv <= INT_MIN) || (rv >= INT_MAX))
			return 0;
	}
	return (neg ? -1 : 1) * static_cast<int>(rv);
}
