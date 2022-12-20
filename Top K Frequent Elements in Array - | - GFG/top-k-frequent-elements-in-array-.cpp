//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;

struct Comp {
    bool operator()(pii a, pii b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num: nums) {
            mp[num]++;
        }
        priority_queue<pii, vector<pii>, Comp> pq;
        for (pii p: mp) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends