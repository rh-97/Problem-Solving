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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root) dfs(root, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, int i) {
        
        if (res.size() > i) {
            
            res[i].push_back(root->val);
            
        } else {
            
            res.push_back({root->val});
        }
        
        if (root->left) f(root->left, i + 1);
        
        if (root->right) f(root->right, i + 1);
    }
};




// BFS
// O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> tree;
        
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        
        while (!Q.empty()) {
            
            vector<int> level;
            
            int n = Q.size();
            
            for (int i = 0; i < n; ++i) {
                
                TreeNode *node = Q.front();
                Q.pop();
                
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                
                level.push_back(node->val);
            }
            
            tree.push_back(level);
        }
        
        return tree;
    }
};

