//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<int>> dp;
    
    bool is_palindrome(string& str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }
    
    int palindromicPartition(string& str, int i, int j) {
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (i >= j or is_palindrome(str, i, j - 1)) return 0;
        
        int res = INT_MAX;
        
        for (int k = i+1; k < j; ++k) {
            res = min(res, palindromicPartition(str, i, k) + palindromicPartition(str, k, j) + 1);
        }
        
        return dp[i][j] = res;
    }
    
    
    int palindromicPartition(string str)
    {
        dp.resize(str.length(), vector<int>(str.length()+1, -1));
        return palindromicPartition(str, 0, str.length());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends