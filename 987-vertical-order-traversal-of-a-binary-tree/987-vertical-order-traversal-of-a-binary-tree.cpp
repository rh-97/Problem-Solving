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


struct Node {
    int x, y;
    int v;
    Node(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
};

class Solution {
public:
    vector<Node> arr;
    void dfs(TreeNode *root, int r, int c) {
        if (root == nullptr) return;
        arr.push_back(Node(r, c, root->val));
        dfs(root->left, r+1, c-1);
        dfs(root->right, r+1, c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(arr.begin(), arr.end(), [&] (Node a, Node b) {
            if (a.y == b.y) {
                if (a.x == b.x) {
                    return a.v < b.v;
                }
                return a.x < b.x;
            }
            return a.y <b.y;
        });
        int d = arr[0].y;
        int n = arr.back().y - d + 1;
        vector<vector<int>> res(n);
        for (Node& node : arr) {
            int tid = node.y - d;
            res[tid].push_back(node.v);
        }
        
        return res;
    }
};