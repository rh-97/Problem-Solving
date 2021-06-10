// DP + Monoqueue
// O(n)


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> dp(n);
        dp[0] = nums[0];
        
        deque<int> dq;
        dq.push_back(0);
        
        
        for (int i = 1; i < n; ++i) {
            
            dp[i] = nums[i] + dp[dq.front()];
            
            if (!dq.empty() and dq.front() == i - k) dq.pop_front();
            
            while (!dq.empty() and dp[dq.back()] <= dp[i]) dq.pop_back();
            
            dq.push_back(i);
                
        }
        
        return dp[n - 1];
    }
};



