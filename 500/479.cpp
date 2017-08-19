/*
    Find the largest palindrome made from the product of two n-digit numbers.

    Since the result could be very large, you should return the largest palindrome mod 1337.

    Example:

    Input: 2

    Output: 987

    Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

    Note:

    The range of n is [1,8].
*/

class Solution {
public:
    int largestPalindrome(int n) {
        long long num = 0;
        for(int i = 0; i < n; ++i)
        {
            num = 10 * num + 9;
            //cout << num << endl;
        }
        //cout << num << endl;
        
        long long maximum = INT_MIN; 
        for(long long i = num; i >= 0; --i)
        {
            if(maximum >= i * num)
                break;
            
            for(long long j = num; j >= i; --j)
            {
                //cout << i << " * " << j << endl;
                long long product = i * j;
                //cout << product << endl;
                if(maximum < product && isPalindrome(product))
                {
                    maximum = product;
                    break;
                }
            }
        }
        
        return maximum % 1337;
    }
    
private:
    bool isPalindrome(long long n)
    {
        if(n < 10)
            return true;
        
        long long ntemp = n;
        long long reverse = 0;
        while(1)
        {
            if(ntemp == reverse)
                return true;
            
            if(ntemp < reverse)
                break;
            
            reverse = 10 * reverse + ntemp % 10;
            ntemp /= 10;
        }
        
        return false;
    }
};
