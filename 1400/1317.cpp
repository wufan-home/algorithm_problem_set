class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> rv({0, 0});
        int temp = n;
        
        // For the last digit.
        int digit = n % 10;
        if(digit == 1) {
            rv[0] = 2;
            n -= 2;
        } else {
            rv[0] = 1;
            n -= 1;
        }
        
        int base = 10;
        for(n /= 10; n > 9; n /= 10, base *= 10)
        {
            int digit = n % 10;
            if (digit == 1) {
                rv[0] += 2 * base;
                n -= 2;
            } else {
                rv[0] += base;
                n -= 1;
            }
        }
        
        rv[1] = temp - rv[0];
        return rv;
    }
};
