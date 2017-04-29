/*
  Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
  For example, given the range [5, 7], you should return 4.
*/


int rangeBitwiseAnd(int m, int n) {
        return (m < n ? rangeBitwiseAnd(m >> 1, n >> 1) << 1 : m);
}

int rangeBitwiseAnd1(int m, int n) {
        int bits = 0;
        while(m < n)
        {
            m >>= 1;
            n >>= 1;
            ++bits;
        }
        
        return m << bits;
}

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int lower = 1;
        while(lower < INT_MAX)
        {
            const int upper = lower == INT_MAX / 2 + 1 ? INT_MAX : 2 * lower - 1;
            if(m == 0 || n == 0 || m == n)
                return m;
            else if(lower <= m && n <= upper)
                return rangeBitwiseAnd(m ^ lower, n ^ lower) | lower;
            else if(m < lower && lower <= n)
                return 0;
            lower = upper + 1;
        }
    }
};
