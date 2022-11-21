//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> dp;

    int f(int arr[], int i, int j) {
        if (j - i + 1 <= 2) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        int cnst = arr[i] * arr[j];
        
        for (int k = i + 1; k < j; ++k) {
            res = min(res, f(arr, i, k) + f(arr, k, j) + cnst *arr[k]);
        }
        
        return dp[i][j] = res;
    }

    int matrixMultiplication(int N, int arr[])
    {
        dp.resize(N, vector<int>(N, -1));
        return f(arr, 0, N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends