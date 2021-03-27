/*
    Serialization is the process of converting a data structure or object into a sequence of bits 
    so that it can be stored in a file or memory buffer, 
    or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary search tree. 
    There is no restriction on how your serialization/deserialization algorithm should work. 
    You just need to ensure that a binary search tree can be serialized to a string 
    and this string can be deserialized to the original tree structure.

    The encoded string should be as compact as possible.

    Note: Do not use class member/global/static variables to store states. 
    Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            
            res.append(cur == NULL ? "NULL" : to_string(cur->val));
            res.push_back(',');
            
            if(cur != NULL)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *res = NULL;
        queue<TreeNode *> q;
        for(int i = 0; i < data.size();)
        {
            if(data[i] == ',')
                ++i;
            else
            {
                string val;
                int j = i;
                for(; j < data.size() && data[j] != ','; ++j) 
                    val.push_back(data[j]);
                
                i = j + 1;
                
                TreeNode *cur = NULL;
                if(val != "NULL")
                    cur = new TreeNode(atoi(val.c_str()));
                
                q.push(cur); 
            }
        }
        
        if(q.empty())
            return res;
        
        res = q.front();
        queue<TreeNode *> q1;
        q1.push(q.front());
        q.pop();
        while(!q.empty())
        {
            TreeNode *cur = q1.front();
            q1.pop();
            cur->left = q.front();
            q.pop();
            if(cur->left != NULL)
                q1.push(cur->left);
            
            cur->right = q.front();
            q.pop();
            if(cur->right != NULL)
                q1.push(cur->right);
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
