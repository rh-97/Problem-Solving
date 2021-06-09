// Recursion
// O(n)

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            in[inorder[i]] = i;
        }
        pre_in = 0;
        return f(preorder, 0, n - 1);
    }
    
private:
    int pre_in;
    unordered_map<int, int> in;
    TreeNode* f(vector<int> &preorder, int L, int R) {
        TreeNode *root = new TreeNode(preorder[pre_in]);
        int index = in[preorder[pre_in++]];
        if (L < index) {
            root->left = f(preorder, L, index - 1);
        }
        if (R > index) {
            root->right = f(preorder, index + 1, R);
        }
        return root;
    }
};














