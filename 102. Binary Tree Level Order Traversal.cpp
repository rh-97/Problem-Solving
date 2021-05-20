
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


// DFS
// O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root) dfs(root);
        return res;
    }
    
private:
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, int level = 0) {
        
        if (res.size() > level) {
            
            res[level].push_back(root->val);
            
        } else {
            
            res.push_back({root->val});
        }
        
        if (root->left) dfs(root->left, level + 1);
        
        if (root->right) dfs(root->right, level + 1);
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

