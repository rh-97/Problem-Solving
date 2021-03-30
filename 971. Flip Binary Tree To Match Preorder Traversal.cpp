// DFS
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        stack<TreeNode*> S;
        S.push(root);
        vector<int> flip;
        int i = 0, n = voyage.size();
        while (!S.empty()) {
            TreeNode* node = S.top();
            S.pop();
            if (node) {
                if (node->val != voyage[i++]) {
                    flip.clear();
                    flip.push_back(-1);
                    break;
                } else if (i < n and node->left and node->left->val != voyage[i]) {
                    flip.push_back(node->val);
                    S.push(node->left);
                    S.push(node->right);
                } else {
                    S.push(node->right);
                    S.push(node->left);
                }
            }
        }
        return flip;
    }
};




