/*
    You need to construct a binary tree from a string consisting of parenthesis and integers.

    The whole input represents a binary tree. It contains an integer followed by zero, 
    one or two pairs of parenthesis. 
    The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

    You always start to construct the left child node of the parent first if it exists.

    Example:
    Input: "4(2(3)(1))(6(5))"
    Output: return the tree root node representing the following tree:

           4
         /   \
        2     6
       / \   / 
      3   1 5   
    Note:
    There will only be '(', ')', '-' and '0' ~ '9' in the input string.
    An empty tree is represented by "" instead of "()".
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        TreeNode *root = NULL;
        if(s == "")
            return root;
        
        return createTree(s, 0, s.size() - 1);
    }
    
private:
    TreeNode *createTree(const string &s, int start, int end)
    {
        TreeNode *root = NULL;
        
        if(start > end)
            return root;
        
        int index = start;
        int valLen = 0;
        for(; index <= end && s[index] != '('; ++index, ++valLen) {}
        root = new TreeNode(atoi(s.substr(start, valLen).c_str()));
        
        if(index <= end && s[index] == '(')
        {
            int p = 1;
            int lstart = ++index;
            for(; index < s.size() && p > 0; ++index)
            {
                if(s[index] == '(')
                    ++p;
                else if(s[index] == ')')
                    --p;
            }
            int lend = index - 2;
            root->left = createTree(s, lstart, lend);
        }
        
        if(index <= end && s[index] == '(')
        {
            int p = 1;
            int rstart = ++index;
            for(; index < s.size() && p > 0; ++index)
            {
                if(s[index] == '(')
                    ++p;
                else if(s[index] == ')')
                    --p;
            }
            int rend = index - 1;            
            root->right = createTree(s, rstart, rend);
        }
        
        return root;
    }
};
