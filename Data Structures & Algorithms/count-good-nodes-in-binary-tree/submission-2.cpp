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

class Solution {
public:
    int count = 0;
    void dfs(TreeNode* node,int maxi)
    {
        if(node == nullptr) return;
        if(node->right)
        {
            if(node->right->val >= maxi)
            {
                count++;
                dfs(node->right,node->right->val);
            }
            else dfs(node->right,maxi);
        }
        if(node->left)
        {
            if(node->left->val >= maxi)
            {
                count++;
                dfs(node->left,node->left->val);
            }
            else dfs(node->left,maxi);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
        {
            return count;
        }
        count++; // root is always goodnode
        dfs(root,root->val);
        return count;
    }
};
