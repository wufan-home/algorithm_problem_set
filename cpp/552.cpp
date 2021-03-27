/*
    Given a positive integer n, return the number of all possible attendance records with length n, 
    which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

    A student attendance record is a string that only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.
    A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

    Example 1:
    Input: n = 2
    Output: 8 
    Explanation:
    There are 8 records with length 2 will be regarded as rewardable:
    "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
    Only "AA" won't be regarded as rewardable owing to more than one absent times.
*/

class Solution {
public:
    int checkRecord(int n) {
        int M = (int)pow(10, 9) + 7;
        
        vector<int> p(n, 0);
        vector<int> l(n, 0);
        vector<int> a(n, 0);
        
        p[0] = 1;
        l[0] = 1;
        l[1] = 3;
        a[0] = 1;
        a[1] = 2;
        a[2] = 4; // p[1] + l[1];
        
        for(int i = 1; i < n; ++i)
        {
            p[i] = ((p[i - 1] + l[i - 1]) % M + a[i - 1]) % M;
            
            if(i > 1)
                l[i] = ((p[i - 1] + a[i - 1]) % M + (p[i - 2] + a[i - 2]) % M) % M;
            
            if(i > 2)
                a[i] = ((a[i - 1] + a[i - 2]) % M + a[i - 3]) % M;
        }
        
        return ((p[n - 1] + l[n - 1]) % M + a[n - 1]) % M;
    }
};
