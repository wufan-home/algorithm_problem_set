/*
    If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

    For each integer in this list:
    The hundreds digit represents the depth D of this node, 1 <= D <= 4.
    The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. 
    The position is the same as that in a full binary tree.
    The units digit represents the value V of this node, 0 <= V <= 9.
    Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. 
    You need to return the sum of all paths from the root towards the leaves.

    Example 1:
    Input: [113, 215, 221]
    Output: 12
    Explanation: 
    The tree that the list represents is:
        3
       / \
      5   1

    The path sum is (3 + 5) + (3 + 1) = 12.
    Example 2:
    Input: [113, 221]
    Output: 4
    Explanation: 
    The tree that the list represents is: 
        3
         \
          1

    The path sum is (3 + 1) = 4.
*/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if(nums.empty())
            return INT_MIN;
        
        res = 0;
        getSum(nums, 1, 1, 0);
        
        return res;
    }
    
private:
    int getSum(vector<int> &nums, int level, int node, int curSum)
    {
        int index = 0;
        for(; index < nums.size(); ++index)
        {
            int curLevel = nums[index] / 100;
            int curNode = (nums[index] / 10) % 10;
            if(curLevel == level && curNode == node)
                break;
        }
        
        if(index == nums.size())
            return INT_MIN;
        
        int val = nums[index] % 10;
        
        int left = getSum(nums, level + 1, 2 * node - 1, curSum + val);
        int right = getSum(nums, level + 1, 2 * node, curSum + val);
        
        if(left == INT_MIN && right == INT_MIN)
            res += curSum + val;
        
        return val;
    }
    
    int res;
};
