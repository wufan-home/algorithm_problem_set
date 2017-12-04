/*
  Implement int sqrt(int x).
  Compute and return the square root of x.

  Solution:
  Do a binary search on the array [0, ..., n / 2]
  such that mid * mid = x.
*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(mid < x / mid)
                l = mid + 1;
            else
                r = mid;
        }
        
        return l > x / l ? l - 1 : l;
    }
};
