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

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        vector<vector<pair<string, int>>> dp(17);
        for (string &word : words) {
            dp[word.length()].push_back({word, 1});
        }
        
        int max_chain = 0;
        
        for (int len = 2; len < 17; ++len) {
            for (auto &[word, chain] : dp[len]) {
                for (auto &[pred, pred_chain] : dp[len - 1]) {
                    if (predecessor(pred, word)) {
                        chain = max(chain, 1 + pred_chain);
                    }
                }
                max_chain = max(max_chain, chain);
            }
        }
        
        return max_chain;
    }
    
private:
    bool predecessor(string &pred, string &word) {
        int n = pred.length();
        int m = word.length();
        
        for (int i = 0, j = 0; i < n and j < m; ) {
            if (pred[i] == word[j]) {
                ++i;
                ++j;
            } else {
                ++j;
                if (j - i >= 2) {
                    return false;
                }
            }
        } 
        
        return true;
    }
};

// or

class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};


