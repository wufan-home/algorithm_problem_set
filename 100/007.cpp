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
