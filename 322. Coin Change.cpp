/* PROBLEM STATEMENT

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that 
you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

// SOLUTION
// Dynamic Programming
// O(amount * n), here n is the size of coins

// Top-Down Recursive Approach
class Solution {
public:
    vector<int> count;
    Solution() : count(10001) {}
    int coinChange(vector<int>& coins, int amount) {
        if (count[amount]) return count[amount];
        int minn = INT_MAX;
        for (int coin : coins) {
            int temp = amount - coin;
            if (temp > 0) temp = coinChange(coins, temp);
            if (temp >= 0 and temp < minn - 1) minn = temp + 1;
        }
        count[amount] = minn == INT_MAX ? -1 : minn;
        return amount ? count[amount] : 0;
    }
};

// Bottom-Up Iterative Approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};

