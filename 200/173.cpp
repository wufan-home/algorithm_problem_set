/*
    Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

    Calling next() will return the next smallest number in the BST.

    Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        mCur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return mCur != NULL || !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = 0;
        if(mCur)
        {
            while(mCur)
            {
                st.push(mCur);
                mCur = mCur->left;
            }

            mCur = st.top();
            st.pop();
        }
        else
        {
            mCur = st.top();
            st.pop();
        }
        
        res = mCur->val;
        
        mCur = mCur->right;

        return res;
    }
    
private:
    TreeNode *mCur;
    
    stack<TreeNode *> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
