/* PROBLEM STATEMENT

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

// SOLUTION
// BFS
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector <double> averages;
        while (!Q.empty()) {
            queue<TreeNode*> q;
            swap(Q, q);
            long long sum = 0;
            int n = q.size();
            while (!q.empty()) {
                TreeNode* node = q.front();
                sum += node->val;
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                q.pop();
            }
            averages.push_back((double) sum / (double) n);
        }
        return averages;
    }
};

