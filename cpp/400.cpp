/*
    Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

    Note:
    n is positive and will fit within the range of a 32-bit signed integer (n < 231).

    Example 1:

    Input:
    3

    Output:
    3
    Example 2:

    Input:
    11

    Output:
    0

    Explanation:
    The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)
            return n;
        
        long long base = 9;
        long long digit = 1;
        long long start = 1;
        while(n >= digit * base)
        {
            n -= digit * base;
            base *= 10;
            ++digit;
            start *= 10;
        }
        
        if(n > digit)
        {
            start += n / digit;
            n %= digit;
        }
        
        if(n == 0)
            return (start - 1) % 10;
        else
            return (start / int(pow(10, digit - n))) % 10;
    }
};
