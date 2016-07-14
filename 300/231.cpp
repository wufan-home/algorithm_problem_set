/*
  Given an integer, write a function to determine if it is a power of two.

  Solution: A integer n which is a power of 2 if and only if  n is of the form
  1000...000. That is its binary expansion is all zeros except the first digit being 1.
  This means that n = 2^ t iif n & (n - 1) == 0.
*/

bool isPowerOfTwo(int n) {
	return (n > 0 && (n & (n - 1) == 0));
}
