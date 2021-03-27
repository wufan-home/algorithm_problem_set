/*
    Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

    Example 1:
    Input: 5
    Output: True
    Explanation: 1 * 1 + 2 * 2 = 5
    Example 2:
    Input: 3
    Output: False
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 3)
            return true;
        
        double error = 0.00000001;
        int root = sqrt(c);
        for(int i = root; i >= 1; --i)
        {
            double squareRoot = sqrt(c - i * i);
            if(squareRoot - (int)squareRoot < error)
                return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 3)
            return true;
        
        while(c % 2 == 0)
            c /= 2;
        
        //cout << c << endl;
        
        //int bound = c / 3;
        for(int k = 3; k <= c; k += 2)
        {
            if(c % k == 0)
            {
                int index = 0;
                while(c % k == 0)
                {
                    ++index;
                    c /= k;
                }
                
                //cout << k << " - " << index << endl;
                if(k % 4 == 3 && index % 2 == 1)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
