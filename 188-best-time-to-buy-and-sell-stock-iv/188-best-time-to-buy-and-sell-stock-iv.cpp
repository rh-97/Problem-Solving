class Solution {
public:
    
    vector<vector<vector<int>>> memo;
    int n;
    int _k;
    
    
    int top_down(vector<int>& prices, int day, int k, int hold) {
        
        if (day == n or k == 0) return 0;
        
        if (memo[k][day][hold] != -1) return memo[k][day][hold];
        
        if (hold) {   // sell
            memo[k][day][hold] = max(prices[day] + top_down(prices, day+1, k-1, 0), top_down(prices, day+1, k, hold));
        } else {   //buy
            memo[k][day][hold] = max(-prices[day] + top_down(prices, day+1, k, 1), top_down(prices, day+1, k, hold));
        }
        
        return memo[k][day][hold];
        
    }
    
    
    int bottom_up(vector<int>& prices) {
        
        for (int j = n-1; j >= 0; --j) {
           for (int i = 1; i <= _k; ++i)  {
                for (int h = 0; h < 2; ++h) {
                    if (h == 1) memo[i][j][h] = max(prices[j] + memo[i-1][j+1][0], memo[i][j+1][1]);
                    else memo[i][j][h] = max(-prices[j] + memo[i][j+1][1], memo[i][j+1][0]);
                }
            }
        }
        
        return memo[_k][0][0];
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        
        _k = k;
        n = prices.size();
        
        
        // memo.resize(_k+1, vector<vector<int>> (n, vector<int> (2, -1)));
        // return top_down(prices, 0, _k, 0);
     
        memo.resize(_k+1, vector<vector<int>> (n+1, vector<int> (2, 0)));
        return bottom_up(prices);
        
    }
};