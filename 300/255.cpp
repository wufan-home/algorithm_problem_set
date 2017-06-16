/*
    Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

    You may assume each number in the sequence is unique.

    Follow up:
    Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() <= 2)
            return true;
            
        int minValue = INT_MIN;
        stack<int> stackForPreMinValues;
        for(int i = 0; i < preorder.size(); ++i)
        {
            if(preorder[i] < minValue)
                return false;
                
            if(i == 0 || preorder[i] > preorder[i - 1])
            {
                while(!stackForPreMinValues.empty() && preorder[i] > stackForPreMinValues.top())
                {
                    minValue = stackForPreMinValues.top();
                    stackForPreMinValues.pop();
                }
            }
            
            stackForPreMinValues.push(preorder[i]);
        }
        
        return true;
    }
};
