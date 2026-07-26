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
    
    int sum(TreeNode* root,int& ans) {
        if(root == nullptr) return 0;
        int left = max(0,sum(root->left,ans));
        int right = max(0,sum(root->right,ans));
        ans = max(ans, left + right + root->val);
        return max(0,root->val + max(sum(root->left,ans),sum(root->right,ans)));
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = root->val;
        sum(root,ans);
        return ans;
    }
};
