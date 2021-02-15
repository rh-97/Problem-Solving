/* PROBLEM STATEMENT  

Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
*/

// SOLUTIOPN
// O(m log mn + k)

class Solution {
public:
    struct P {
        int index;
        int sum;
    };
    static bool compare(P a, P b) {
        return a.sum < b.sum ? true : a.sum == b.sum ? a.index < b.index : false;
    }
    int row_sum_soldiers(const vector<int>& vec) {
        int left = 0, right = vec.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (vec[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<P> counts(m);
        for (int i = 0; i < m; ++i) {                 //O(m log n)
            counts[i].index = i;
            counts[i].sum = row_sum_soldiers(mat[i]);
        }
        sort(counts.begin(), counts.end(), compare);  //O(m log m)
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = counts[i].index;
        }
        return res;
    }
};

// Coplexity Calculation:
// O(m log n + m log m + k) = O(m (log m + log n) + k) = O(m log mn + k)



