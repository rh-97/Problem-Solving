// Bit manipulation
// O(n^2 + n*N)

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        int i = 0;
        for (string &word : words) {
            for (char &c : word) {
                mask[i] |= (1 << (c - 'a'));
            }
            ++i;
        }
        size_t res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(mask[i] & mask[j])) {
                    res = max(res, words[i].size() * words[j].size());
                }
            }
        }
        return res;
    }
};







