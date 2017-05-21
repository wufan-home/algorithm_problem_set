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
        int range = 0;
        for(int i = 0; m != 0; ++i)
        {
            int digitm = m & 1;
            int digitn = n & 1;
            if(digitm != digitn)
                range = 0;
                
            range |= (digitm << i);
            m >>= 1;
            n >>= 1;
        }
        
        return n == 0 ? range : 0;
    }
};
