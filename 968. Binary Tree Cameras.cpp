// Greedy
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
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) ++cams;
        return cams;
    }
    
private:   
    int cams = 0;
    
    int dfs(TreeNode *root) {
        if (!root) return 2;
        int l = dfs(root->left), r = dfs(root->right);
        if (l == 2 and r == 2) return 0; // 2 -> covered but no cam
        if (l == 0 or r == 0) {   // 0 -> not covered
            ++cams;
            return 1;
        }
        return 2;   // 1 -> cam
    }
};




