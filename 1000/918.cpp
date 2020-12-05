/*
  Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

  Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

  Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



  Example 1:

  Input: [1,-2,3,-2]
  Output: 3
  Explanation: Subarray [3] has maximum sum 3
  Example 2:

  Input: [5,-3,5]
  Output: 10
  Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
  Example 3:

  Input: [3,-1,2,-1]
  Output: 4
  Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
  Example 4:

  Input: [3,-2,2,-3]
  Output: 3
  Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
  Example 5:

  Input: [-2,-3,-1]
  Output: -1
  Explanation: Subarray [-1] has maximum sum -1


  Note:

  -30000 <= A[i] <= 30000
  1 <= A.length <= 30000
*/

/*
  Solution: The problem actually finds the maixium value of the following five sum categories:
  1. Prefix sums.
  2. Suffix sums.
  3. Interval sums.
  4. The substract of total sum and interval sums.
  5. The total sum.
  
  It is easy to see that a circular sum starting with bigger index and ending with a smaller index is actually
  a substract of the total sum and a interval sum. This implies that the set of circular sums and interval sums are one to one match.
  It implies that the maximum circular sum is nothing but the total sum minus the minimum interval sum.
  
  This logic can also be applied to the relationships between prefix sums and suffix sums.
  
  Then, the algorithm can be described as follows. From the leftmost to the rightmost of the array,
  1. Maintian the following five values:
  1.1. The maximum prefix value for each index.
  1.2. The minimum prefix value for each index. This value corresponds the maximum suffix sum.
  1.3. The maximum interval value end with each index.
  1.4. The mimimum interval value end with each index. This value corresponds the maximum circular sum.
  1.5. The total sum.
  2. Return the maximum value of the above five values.
  
  Since there is a partial order of the maximum or minimum values, it is enough to use one variable for each item. This means the space complexity is O(1).
  
  The time complexity is O(N).
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1)
            return A[0];
            
        int len = A.size();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += A[i];
        }
        
        int min_prefix = A[0];
        int max_prefix = A[0];
        int min_interval = A[0];
        int max_interval = A[0];
        int prefix = A[0];
        for (int i = 1; i < len - 1; ++i) {
            prefix += A[i];
            
            if (prefix - min_prefix > max_interval)
                max_interval = prefix - min_prefix;
            
            if (prefix - max_prefix < min_interval)
                min_interval = prefix - max_prefix;
            
            if (prefix > max_prefix)
                max_prefix = prefix;
            
            if (prefix < min_prefix)
                min_prefix = prefix;
        }
        
        return max(sum, max(max_prefix, max(max_interval, max(sum - min_prefix, sum - min_interval))));
    }
};
