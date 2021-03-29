/*
    The gray code is a binary numeral system where two successive values differ in only one bit.

    Given a non-negative integer n representing the total number of bits in the code, 
    print the sequence of gray code. A gray code sequence must begin with 0.

    For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

    00 - 0
    01 - 1
    11 - 3
    10 - 2
    Note:
    For a given n, a gray code sequence is not uniquely defined.

    For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

    For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
            return vector<int>(1, 0);

        vector<int> base({0, 1});
        if(n == 1)
            return base;
            
        int upper = 1;
        for(int i = 2; i <= n; ++i)
        {
            upper <<= 1;
            int prevSize = base.size();
            base.resize(2 * prevSize, upper);
            for(int i = prevSize, j = prevSize - 1; i < base.size(); ++i, --j)
                base[i] |= base[j];
        }
        
        return base;
    }
};
