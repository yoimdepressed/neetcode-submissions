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
    unordered_map<int,int> map;
    int idx = 0;
    TreeNode* build(vector<int> & preorder, int start,int end)
    {
        if(start > end) return nullptr;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int i = map[val];
        root->left = build(preorder,start,i-1);
        root->right = build(preorder,i+1,end);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i < inorder.size();i++)
        {
            map[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size()-1);

    }
};
