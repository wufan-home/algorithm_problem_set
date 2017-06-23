/*
    Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

    If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

    Example 1
    Input:

    48 
    Output:
    68
    Example 2
    Input:

    15
    Output:
    35
*/

class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10)
            return a;

        vector<int> factorMultiplicityList(10, 0);
        factorMultiplicityList[8] = getFactorMultiplicity(a, 8);
        for(int i = 9; i >= 2; --i)
        {
            if(i == 8)
                continue;
                
            factorMultiplicityList[i] = getFactorMultiplicity(a, i);
        }
        
        if(a >= 10)
            return 0;
        
        int factorization = 0;
        int bound = INT_MAX / 10;
        for(int i = 2; i < 10; ++i)
        {
            for(int j = 0; j < factorMultiplicityList[i]; ++j)
            {
                if(factorization > bound || (factorization == bound && i > 7))
                    return 0;
                
                factorization = 10 * factorization + i;
            }
        }
        
        return factorization;
    }
    
private:
    int getFactorMultiplicity(int& num, int factor)
    {
        int count = 0;
        for(; num % factor == 0; ++count, num /= factor) {}
        return count;
    }
};
