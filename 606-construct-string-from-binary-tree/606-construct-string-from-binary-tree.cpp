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
    string tree2str(TreeNode* root) {
        
        if (root == nullptr) return "";
        
        string L = tree2str(root->left);
        string R = tree2str(root->right);
        
        string res = to_string(root->val);
        
        if (R != "") {
            res += "(" + L + ")" + "(" + R + ")";
        } else if (L != "") {
            res += "(" + L + ")";
        }
        
        return res;
    }
};