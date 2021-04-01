// Greedy
// O(n * (n - m))
class Solution {
public:
    int m, n;
    vector<int> movesToStamp(string stamp, string target) {
        m = stamp.size();
        n = target.size();
        int limit = n - m;
        int count = 0;
        vector<bool> vis(n, false);
        vector<int> seq;
        while (count != n) {
            int sz = seq.size();
            for (int i = 0; i <= limit; ++i) {
                if (!vis[i] and match(stamp, target, i)) {
                    vis[i] = true;
                    seq.push_back(i);
                    replace(target, i, count);
                    if (count == n) break;
                }
            }
            if (sz == seq.size()) return {};
        }
        reverse(seq.begin(), seq.end());
        return seq;
    }
    bool match(string &stamp, string &target, int i) {
        for (int j = 0; j < m; ++j, ++i) {
            if (target[i] != stamp[j] and target[i] != '?') {
                return false;
            }
        }
        return true;
    }
    void replace(string &target, int i, int &count) {
        int limit = i + m;
        for (; i < limit; ++i) {
            if (target[i] != '?') target[i] = '?', ++count;
        }
    }
};






