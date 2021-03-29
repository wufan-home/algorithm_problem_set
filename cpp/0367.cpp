/*
    Given a positive integer num, write a function which returns True if num is a perfect square else False.

    Note: Do not use any built-in library function such as sqrt.

    Example 1:

    Input: 16
    Returns: True
    Example 2:

    Input: 14
    Returns: False
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2)
            return num >= 0;
            
        for(int smaller = 2, larger = num - 1; smaller < larger;)
        {
            int mid = smaller + (larger - smaller) / 2;
            int quotient = num / mid;
            if(num % mid == 0 && mid == quotient)
                return true;
            else if(mid < quotient)
                smaller = mid + 1;
            else
                larger = mid;
        }
        
        return false;
    }
};
