/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> Q;
        Q.push(root);
        vector<vector<int>> res = {{root->val}};
        while (!Q.empty()) {
            int sz = Q.size();
            vector<int> arr;
            for (int i = 0; i < sz; ++i) {
                Node * nd = Q.front();
                Q.pop();
                for (Node *child : nd->children) {
                    Q.push(child);
                    arr.push_back(child->val);
                }
            }
            if (!arr.empty()) res.push_back(arr);
        }
        return res;
    }
};