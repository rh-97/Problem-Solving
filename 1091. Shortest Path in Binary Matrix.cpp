/* PROBLEM STATEMENT 
In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
   Hide Hint #1  
Do a breadth first search to find the shortest path.

*/

// SOLUTION
// Breadth First Search
// O(n)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        if (grid[0][0] == 1 or grid[n][n] == 1) return -1;
        int lv = 1; 
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        grid[0][0] = 1;
        while (!Q.empty()) {
            queue<pair<int, int>> temp;
            swap(Q, temp);
            while (!temp.empty()) {
                pair<int, int> p = temp.front();
                if (p.first == n and p.second == n) return lv;
                temp.pop();
                for (int i = p.first - 1; i <= p.first + 1; ++i) {
                    if (i >=0 and i <= n) {
                        for (int j = p.second - 1; j <= p.second + 1; ++j) {
                            if (j >= 0 and j <= n and grid[i][j] == 0) {
                                Q.push({i, j});
                                grid[i][j] = 1;
                            }
                        }
                    }
                }
            }
            ++lv;
        }
        return -1;
    }
};


