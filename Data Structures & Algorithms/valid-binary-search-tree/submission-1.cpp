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
    bool validate(TreeNode* root,int maxi,int mini)
    {
        if(root == nullptr) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return validate(root->left,root->val,mini) && validate(root->right,maxi,root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return validate(root,INT_MAX,INT_MIN);

    }
};
