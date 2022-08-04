class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mn_len = INT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            mn_len = min(mn_len, int(strs[i].size()));
        }
        int prefix_len = 0;
        bool f = false;
        for (int i = 0; i < mn_len; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) {
                    f = true;
                    break;
                }
            }
            if (f) {
                break;
            }
            prefix_len++;
        }
        
        return strs[0].substr(0, prefix_len);
    }
};