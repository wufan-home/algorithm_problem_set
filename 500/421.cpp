/*
    Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

    Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

    Could you do this in O(n) runtime?

    Example:

    Input: [3, 10, 5, 25, 2, 8]

    Output: 28

    Explanation: The maximum result is 5 ^ 25 = 28.
    
    Solution:
    1. The maximal result must be (in decimal form) combination of 0 and 1,
       and 1 must be placed as left as best.
    2. The key idea of this solution is to use a prefix tree (trie) method to test all elements of input.
    3. The candidate prefix will increase a digit 1 each round. 
       And then, use this prefix to do the XOR to every prefix in the set. 
       If there are two prefixs combine this prefix 
       (Here, we use a typical application of hash sets, i.e., check the result exists in the S)
       generate this prefix, the newly added 1 will be remained. Otherwise, the 1 will be discarded,
       and then the new digit will be 0 autometically.
    4. We do not need to worry about we use different pairs of intergers in step 3. 
       This search is done by prefix. 
       Hence, even we use different pair of integers, they also belong to the same branch of the prefix tree.
       This is the reason why we say the key idea is to apply the prefix tree method.
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int res = 0;
        for(int i = 31; i >= 0; --i)
        {
            mask |= (1 << i);
            set<int> S;
            for(auto a : nums)
                S.insert(mask & a);
            
            int cur = (res | 1 << i);
            for(auto prefix : S)
            {
                if(S.find(prefix ^ cur) != S.end())
                {
                    res = cur;
                    break;
                }
            }
        }
        
        return res;
    }
};
