//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> currencies = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int M = 10;
        
        vector<vector<long>> dp(M+1, vector<long>(N+1, INT_MAX));
        dp[0][0] = 0;
        
	    vector<int> res;
	    
        for (int i = 1; i <= M; ++i) {
	        for (int j = 0; j <= N; ++j) {
	            
	            dp[i][j] = dp[i - 1][j];
	            
	            if (j >= currencies[i - 1]) {
	                dp[i][j] = min(dp[i][j], 1 + dp[i][j - currencies[i - 1]]);
	               // if (dp[i][j] > 1 + dp[i][j - currencies[i - 1]]) {
	               //     dp[i][j] = 1 + dp[i][j - currencies[i - 1]];
	               //     res.push_back(currencies[i - 1]);
	               // }
	            }
	        }
	    }
	    int i = M, j = N;
	    while (i > 0 && j > 0) {
	        if (j >= currencies[i - 1] && dp[i-1][j] > 1 + dp[i][j - currencies[i - 1]]) {
	            res.push_back(currencies[i - 1]);
	            j -= currencies[i - 1];
	        } else --i;
	    }
	    
	    return res;
	    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends