/*  PROBLEM STATEMENT  

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
  */
  
  
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            res.push_back(Q.back()->val);
            queue<TreeNode*> q;
            swap(Q, q);
            while (!q.empty()) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left) Q.push(tmp->left);
                if (tmp->right) Q.push(tmp->right);
            }
        }
        return res;
    }
};
  
  
  
  
  
  
  
  
  
  
  
