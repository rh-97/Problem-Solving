//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        
        // Only for positive numbers
        // int sum = 0, maxLen = 0;
        
        // for (int i = 0, j = 0; j < N; ++j) {
            
        //     sum += A[j];
            
        //     if (sum < K) continue;
            
        //     if (sum == K) maxLen = max(maxLen, j - i + 1);
            
        //     if (sum > K) {
        //         sum -= A[i++];
        //     }
            
        // }
        // return maxLen;
        
        long sum = 0;
        int maxLen = 0;
        unordered_map<long, int> mp;
        mp[0] = -1;
        
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            
            if (mp.count(sum) == 0) mp[sum] = i;
            
            int id = sum - K;
            
            if (mp.count(id) == 1) maxLen = max(maxLen, i - mp[id]);
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends