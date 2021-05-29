// DFS
// O(2^n)


class Solution {
public:
    int totalNQueens(int n) {
        vector<int> board(n);
        return dfs(board);
    }
private:
    int dfs(vector<int> &board, int pos = 0) {
        if (pos == int(board.size())) return 1;
        int sol = 0, n = board.size();
        for (int i = 0; i < n; ++i) {
            bool attacked = false;
            for (int j = 0; j < pos; ++j) {
                if (board[j] == i or abs(j - pos) == abs(board[j] - i)) {
                    attacked = true;
                    break;
                }
            }
            if (attacked) continue;
            board[pos] = i;
            sol += dfs(board, pos + 1);
        }
        return sol;
    }
};





