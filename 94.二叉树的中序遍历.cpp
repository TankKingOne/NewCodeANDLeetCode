/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);
        return ret;
    }
    
    void _inorderTraversal(TreeNode* root)
    {
        if(root)
        {
            _inorderTraversal(root->left);
            ret.push_back(root->val);
            _inorderTraversal(root->right);
        }
    }
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> ret;
        
        if(root == nullptr)
            return ret;
        
        TreeNode* cur = root;
        while(cur || !nodes.empty())
        {
            while(cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            
            nodes.pop();
            cur = nodes.top();
            
            ret.push_back(cur->val);
            cur = cur->right;
        }
        return ret;
    }
};