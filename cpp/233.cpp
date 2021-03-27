/*
    Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

    For example:
    Given n = 13,
    Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
    int countDigitOne(int n) {
        int num = 0;
        if(n <= 0)
            return num;

        long long base = 10;
        if(n < base)
            return 1;

        for(; 10 * base <= n; base *= 10);

        if(n == base) {
            num = base / 10 + 10 * countDigitOne(base / 10- 1) + 1;
        } else if(n % base == 0) {
            num = base + (n / base) * countDigitOne(base - 1);
        } else if(n / base > 1) {
            num = base + (n / base) * countDigitOne(base - 1) + countDigitOne(n % base);
        } else {
            num = n % base + 1 + countDigitOne(base - 1) + countDigitOne(n % base);
        }

        return num;
    }
};
