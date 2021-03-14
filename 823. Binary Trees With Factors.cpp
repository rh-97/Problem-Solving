/* PROBLEM STATEMENT

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of
the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109

*/

// SOLUTION
// Dynamic Programming
// O(n^2), here n is the array length
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int M = 1'000'000'007;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long res = 0;
        unordered_map<long, long> dp;
        for (long i = 0; i < n; ++i) {
            dp[arr[i]] = 1;
            long limit = sqrt(arr[i]);
            for (long j = 0; arr[j] <= limit; ++j) {
                if (arr[i] % arr[j] == 0) {
                    long child = arr[i] / arr[j];
                    if (dp.count(child)) {
                        int temp = (dp[arr[j]] * dp[child])  % M;
                        if (child != arr[j]) temp <<= 1;
                        dp[arr[i]] += temp;
                    }
                }
            }
            res = (res + dp[arr[i]]) % M;
        }
        return res;
    }
};


