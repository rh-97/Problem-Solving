// SOLUTION
// Intuitive
// O(n)
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) ++count[c - 'a'];
        vector<string> eng_rep = {"zero", "two", "four", "six", "eight", "five", "three", "seven", "nine", "one"};
        vector<char> unique = {'z', 'w', 'u', 'x', 'g', 'f', 'h', 'v', 'i', 'o'};
        vector<int> unique_num = {0, 2, 4, 6, 8, 5, 3, 7, 9, 1};
        string res = "";
        for (int i = 0; i < 10; ++i) {
            while (count[unique[i] - 'a']) {
                res += (unique_num[i] + '0');
                for (char c : eng_rep[i]) --count[c - 'a'];
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};











