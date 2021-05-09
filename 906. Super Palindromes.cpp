// BFS & Math
// O(sqrt(right))
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int lb = sqrt(stol(left)), ub = sqrt(stol(right));
        int res = lb <= 3 and 3 <= ub;
        queue<string> Q;
        Q.push("1"), Q.push("2");
        while (true) {
            string str = Q.front(); Q.pop();
            long v = stoi(str);
            if (v > ub) break;
            if (v >= lb and is_palindrome(v * v)) ++res;
            int len = str.size();
            int pos = len >> 1;
            if (len & 1) {
                str.insert(pos, 1, str[pos]);
                Q.push(str);
            } else {
                for (const char &c : {'0', '1', '2'}) {
                    string temp = str;
                    temp.insert(pos, 1, c);
                    Q.push(temp);
                }
            }
        }
        return res;
    }

    bool is_palindrome(long n) {
        return n == reverse_num(n);
    }
    long reverse_num(long n) {
        long ret = 0;
        while (n) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    } 
};
