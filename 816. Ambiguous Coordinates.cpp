//  Brute Force
//  O(n^3)

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        s.erase(n - 1); s.erase(0, 1); n -= 2;
        vector<string> res;
        for (int i = 1; i < n; ++i) {
            vector<string> x = helper(s.substr(0, i)), y = helper(s.substr(i));
            for (string &a : x) {
                for (string &b : y) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
    
private:
    vector<string> helper(string const &s) {
        int n = s.size();
        if (n > 1 and s[0] == '0' and s[n - 1] == '0') {
            return {};
        } else if (n > 1 and s[0] == '0') {
            return {"0." + s.substr(1)};
        } else if (s[n - 1] == '0') {
            return {s};
        }
        vector<string> res = {s};
        for (int i = 1; i < n; ++i) {
            res.push_back(s.substr(0, i) + '.' + s.substr(i));
        }
        return res;
    }
};


