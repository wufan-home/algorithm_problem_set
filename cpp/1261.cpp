/*
    Given a binary tree with the following rules:

    root.val == 0
    If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
    Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

    You need to first recover the binary tree and then implement the FindElements class:

    FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
    bool find(int target) Return if the target value exists in the recovered binary tree.


    Example 1:



    Input
    ["FindElements","find","find"]
    [[[-1,null,-1]],[1],[2]]
    Output
    [null,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1]); 
    findElements.find(1); // return False 
    findElements.find(2); // return True 
    Example 2:



    Input
    ["FindElements","find","find","find"]
    [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
    Output
    [null,true,true,false]
    Explanation
    FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
    findElements.find(1); // return True
    findElements.find(3); // return True
    findElements.find(5); // return False
    Example 3:



    Input
    ["FindElements","find","find","find","find"]
    [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
    Output
    [null,true,false,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
    findElements.find(2); // return True
    findElements.find(3); // return False
    findElements.find(4); // return False
    findElements.find(5); // return True


    Constraints:

    TreeNode.val == -1
    The height of the binary tree is less than or equal to 20
    The total number of nodes is between [1, 10^4]
    Total calls of find() is between [1, 10^4]
    0 <= target <= 10^6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        root_ = root;
        recover(root_, NULL);
    }
    
    bool find(int target) {
        return find_(root_, target);
    }
    
private:
    void recover(TreeNode* current, TreeNode* parent) {
        if (current == NULL) {
            return;
        }
        
        if (parent == NULL) {
            current->val = 0;
        } 
        else if (current == parent->left) {
            current->val = 2 * parent->val + 1;
        }
        else {
            current->val = 2 * parent->val + 2;
        }
        
        recover(current->left, current);
        recover(current->right, current);
    }
    
    bool find_(TreeNode* root, int target) {
        if (root == NULL) {
            return false;
        }
        
        return root->val == target || find_(root->left, target) || find_(root->right, target);
    }
    
    TreeNode* root_;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
