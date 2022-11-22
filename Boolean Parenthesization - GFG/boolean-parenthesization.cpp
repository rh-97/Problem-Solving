//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


    vector<vector<vector<int>>> dp;

    int countWays(string& str, int i, int j, bool T) {
        
        int t = T ? 1 : 0;
        
        if (dp[i+1][j][t] != -1) return dp[i+1][j][t];
        
        if (j - i + 1 == 3) {
            if (T) return int(str[i+1] == 'T');
            else return int(str[i+1] == 'F');
        }
        
        int ways = 0;
        
        for (int k = i+2; k < j; k+=2) {
            int lT = countWays(str, i, k, true);
            int lF = countWays(str, i, k, false);
            int rT = countWays(str, k, j, true);
            int rF = countWays(str, k, j, false);
            
            if (str[k] == '|') {
                if (T) ways += lT * rF + lF * rT + lT * rT;
                else ways += lF * rF;
            } else if (str[k] == '&') {
                if (T) ways += lT * rT;
                else ways += lT * rF + lF * rT + lF * rF;
            } else {
                if (T) ways += lT * rF + lF * rT;
                else ways += lT * rT + lF * rF;
            }
        }
        ways %= 1003;
        return dp[i+1][j][t] = ways;
    }

    int countWays(int N, string S){
        
        dp.resize(N+2, vector<vector<int>>(N+1, vector<int>(2, -1)));
        
        countWays(S, -1, N, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends