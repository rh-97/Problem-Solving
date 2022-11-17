//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        vector<vector<ll>> dp(N+1, vector<ll>(sum+1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= coins[i- 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends