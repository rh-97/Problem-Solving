class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int low = 0, high = n - 1, score = 0, res = 0;
        while (low <= high) {
            if (score < 1 and P < tokens[low]) break;
            if (P < tokens[low] and score >= 1) {
                --score; P += tokens[high--];
            }
            if (P >= tokens[low]) {
                ++score; P -= tokens[low++];
                res = max(res, score);
            }
        }
        return res;
    }
};