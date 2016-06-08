/*
  Implement int sqrt(int x).
  Compute and return the square root of x.

  Solution:
  Do a binary search on the array [0, ..., n / 2]
  such that mid * mid = x.
*/

int mySqrt(int x)
{
        if(x < 0)
		return INT_MIN;

	if(x < 2)
		return x;

	long long x1 = x;
	for(int l = 0, r = x / 2; l <= r;)
	{
		long long mid = l + (r + 1 - l) / 2;
		long long square = mid * mid;
		if(square == x1)
			return mid;
		else if(mid == r)
			return square > x1 ? l : r;
		else if(square > x1)
			r = mid;
		else
			l = mid;
	}
	
	return INT_MIN;
}
