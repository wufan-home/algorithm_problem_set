/*
    Given an integer n, return the number of trailing zeroes in n!.

    Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
            return 0;
            
        int count = 0;
        while(n != 0) {
            n /= 5;
            count += n;
        }
        
        return count;
        
    }
};
