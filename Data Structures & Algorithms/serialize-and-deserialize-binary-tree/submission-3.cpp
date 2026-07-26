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

class Codec {
public:
    
    void ser(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "#,"; 
            return;
        }
        s += to_string(root->val) + ",";
        ser(root->left, s);
        ser(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        ser(root, s);
        return s;
    }
    TreeNode* des(const string& data, int& i) {
        if (i >= data.size()) return nullptr;
        int j = i;
        while (j < data.size() && data[j] != ',') {
            j++;
        }
        string val = data.substr(i, j - i);
        
        i = j + 1;

        if (val == "#") return nullptr;

        // Create node and recurse
        TreeNode* root = new TreeNode(stoi(val));
        root->left = des(data, i);
        root->right = des(data, i);
        
        return root;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return des(data, i);
    }
};
