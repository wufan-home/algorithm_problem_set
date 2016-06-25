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


bool isPalindrome(int x) {
        if(x < 0)
		return false;

	// Magic number 1000000000:
	// Notice that the largest positive integer is 2^31 - 1 = 2147483647.
	// Divide this number won't get more than 1 digit.
	// (Of course, we shall shrink this number until we get one digit by dividing this number.)
	int upper = 1000000000;
	while(upper > x)
		upper /= 10;

	int lower = 10;
	while(lower <= upper)
	{
		if(x / upper != (x % lower))
			return false;

		x %= upper;
		x /= lower;
		upper /= 100; // Discard two digits in one round, then the bound shall divide 100.
	}

	return true;
}
