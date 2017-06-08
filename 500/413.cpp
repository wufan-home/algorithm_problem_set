/*
    A sequence of number is called arithmetic if it consists of at least three elements and 
    if the difference between any two consecutive elements is the same.

    For example, these are arithmetic sequence:

    1, 3, 5, 7, 9
    7, 7, 7, 7
    3, -1, -5, -9
    The following sequence is not arithmetic.

    1, 1, 2, 5, 7

    A zero-indexed array A consisting of N numbers is given. 
    A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

    A slice (P, Q) of array A is called arithmetic if the sequence:
    A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

    The function should return the number of arithmetic slices in the array A.


    Example:

    A = [1, 2, 3, 4]

    return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
            
        vector<int> sliceSizes;
        int d = -1;
        int length = 0;
        for(int l = 0, r = 1; r < A.size(); ++r)
        {
            if(r == l + 1)
            {
                d = A[r] - A[l];
                length = 2;
            }
            else if(d == A[r] - A[r - 1])
                ++length;
            else
            {
                if(length > 2)
                    sliceSizes.push_back(length);

                l = r - 1;
                d = A[r] - A[l];
                length = 2;
            }
        }
        
        if(length > 2)
            sliceSizes.push_back(length);
        
        int total = 0;
        for(int i = 0; i < sliceSizes.size(); ++i)
            total += (sliceSizes[i] - 1) * (sliceSizes[i] - 2) / 2;
            
        return total;
    }
};
