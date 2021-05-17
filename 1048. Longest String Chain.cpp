// DP - Bottom-Up
// O(L^2 * N)

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        S = unordered_set<string>(words.begin(), words.end());
        
        int res = 0;
        
        for (const string &word : words) {
            res = max(res, dfs(word));
        }
        
        return res;
    }

private:
    unordered_map<string, int> memo;
    unordered_set<string> S;
    
    int dfs(const string &word) {
        
        if (memo.count(word)) {
            return memo[word];
        }
        
        int n = word.length();
        int max_chain_len = 1;
        
        for (int i = 0; i < n; ++i) {
            string pred = word.substr(0, i) + word.substr(i + 1);
            if (S.count(pred)) {
                int cur_chain_len = 1 + dfs(pred);
                max_chain_len = max(max_chain_len, cur_chain_len);
            }
        }
        
        return memo[word] = max_chain_len;
    }
};



// DP - Top-Bottom
// O(N * (log N + L^2))

