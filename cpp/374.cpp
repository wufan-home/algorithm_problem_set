/*
  We are playing the Guess Game. The game is as follows:
  I pick a number from 1 to n. You have to guess which number I picked.
  Every time you guess wrong, I'll tell you whether the number is higher or lower.
  You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
  -1 : My number is lower
  1 : My number is higher
  0 : Congrats! You got it!
  Example:
  n = 10, I pick 6.
  Return 6.
*/

int guessNumber(int n)
{
        int l = 0;
        int r = n - 1;
        while(l < r)
        {
		int mid = l + (r + 1 - l) / 2;
		int result = guess(mid + 1);
		if(result < 0) // my number is lower, then the next guess should be lower.
			r = mid - 1;
		else
			l = mid;
        }
        return l + 1;
}
