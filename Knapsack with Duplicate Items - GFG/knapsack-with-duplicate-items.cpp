//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int dp[1001][1001];
    // Solution() {
    //     memset(dp, -1, sizeof dp);
    // }
    

    // int knapSack(int N, int W, int val[], int wt[])
    // {
    //     if (dp[N][W] != -1) return dp[N][W];
    //     if (W == 0 or N == 0) return 0;
        
    //     dp[N][W] = knapSack(N - 1, W, val, wt);
    //     if (W >= wt[N-1])
    //         dp[N][W] = max(dp[N][W], val[N-1]+knapSack(N, W - wt[N-1], val, wt));
        
    //     return dp[N][W];
    // }   
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1] = {0};
        memset(dp, 0, sizeof dp);
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= W; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= wt[i-1]) {
                    dp[i][j] = max(dp[i][j], val[i-1] + dp[i][j - wt[i-1]]);
                }
            }
        }
        
        return dp[N][W];
    }
    
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends