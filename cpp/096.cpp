/*
    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    For example,
    Given n = 3, there are a total of 5 unique BST's.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> amountBySize = vector<int>(n + 1, 1);
        for(int i = 2; i <= n; ++i)
        {
            int amount = 0;
            for(int l = 0; l <= i - 1; ++l)
                amount += amountBySize[l] * amountBySize[i - 1 - l];
                
            amountBySize[i] = amount;
        }
        
        return amountBySize[n];
    }
};
