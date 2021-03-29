/*
    Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

    Example:
    Given n = 2, return 91. 
    (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        long long sum = 1;
        long long part = 1;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0)
                part *= 9;
            else
                part *= 9 - i + 1;
            
            sum += part;
        }
        
        return sum;
    }
};
