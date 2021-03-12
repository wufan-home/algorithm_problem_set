/*
    Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

    Example 1:

    Input: A = [4,5,0,-2,-3,1], K = 5
    Output: 7
    Explanation: There are 7 subarrays with a sum divisible by K = 5:
    [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]



    Note:

        1 <= A.length <= 30000
        -10000 <= A[i] <= 10000
        2 <= K <= 10000


*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int size = A.size();
        vector<int> sums(size, 0);
        
        sums[0] = A[0];
        for (int i = 1; i < size; ++i) {
            sums[i] = A[i] + sums[i - 1];
        }
        
        vector<int> count(K, 0);
        for (int i = 0; i < size; ++i) {
            ++count[getMod(sums[i], K)];
        }
        
        int res = 0;
        
        for (int i = 0; i < K; ++i) {
            res += count[i] * (count[i] - 1) / 2;
        }
        
        return res + count[0];
    }
    
private:
    int getMod(int value, int mod) {
        while (value < 0) {
            value += mod;
        }
        
        return value % mod;
    }
};
