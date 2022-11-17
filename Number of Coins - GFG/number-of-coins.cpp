//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<long>> dp(M+1, vector<long>(V+1, INT_MAX));
	    
	    dp[0][0] = 0;
	    
	    for (int i = 1; i <= M; ++i) {
	        for (int j = 0; j <= V; ++j) {
	            
	            dp[i][j] = dp[i - 1][j];
	            
	            if (j >= coins[i - 1]) {
	                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
	            }
	        }
	    }
	    return dp[M][V] == INT_MAX ? -1 : dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends