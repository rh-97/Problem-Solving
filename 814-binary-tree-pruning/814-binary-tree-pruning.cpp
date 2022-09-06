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
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int L = dfs(root->left);
        if (L == 0) root->left = nullptr;
        
        int R = dfs(root->right);
        if (R == 0) root->right = nullptr;
        
        return (root->val + L + R);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (dfs(root) == 0) return nullptr;
        return root;
    }
};