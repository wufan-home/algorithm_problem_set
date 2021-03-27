/*
  Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
  Example:
  Given num = 16, return true. Given num = 5, return false.
  Follow up: Could you solve it without loops/recursion?

  Solution:
  A inumber is a power of 4 if and only if it is greater than 0, even, a power of two and its value minus 1 is divisible by 3. 
*/

bool isPowerOfFour(int num) {
        return (num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0);
}
