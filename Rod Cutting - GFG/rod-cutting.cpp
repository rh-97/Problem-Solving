//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int dp[1001][1001];
    Solution() {
        memset(dp, -1, sizeof dp);
    }
  
    int cutRod(int price[], int n, int L = -2) {
        
        if (L == -2) L = n;
        
        if (dp[n][L] != -1) return dp[n][L];
        
        if (L == 0 or n == 0) return 0;
        
        dp[n][L] = cutRod(price, n-1, L);
        if (L >= n) dp[n][L] = max(dp[n][L], price[n-1] + cutRod(price, n, L - n));
        
        return dp[n][L];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends