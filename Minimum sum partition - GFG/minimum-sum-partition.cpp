//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// #define int long long
#define ui unsigned int

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, v, n) for (int i = v; i < n; ++i)
#define RFOR(i, v, n) for (int i = n - 1; i >= v; --i)

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vb>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define si stack<int>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define usi unordered_set<int>
#define qi queue<int>

#define all(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second

#define mod 998244353 // 4294967296
#define inf 1000000000000000000
#define nl cout << '\n'

#define addAll(vec, sum)                                                       \
	for (auto &v : vec)                                                        \
	sum += v



class Solution{

  public:
  
    
    int minSubsetSumDiff(const vi &arr) {
    	int n = arr.size();
    
    	int total = 0;
    	addAll(arr, total);
    
    	vvb dp(n + 1, vb(total / 2 + 1));
    	REP(i, n + 1) dp[i][0] = true;
    	FOR(i, 1, n + 1) FOR(j, 1, total/2 + 1) {
    		if (arr[i-1] <= j) {
    			dp[i][j] = dp[i - 1][j - arr[i-1]];
    		}
    		dp[i][j] = dp[i][j] || dp[i - 1][j];
    	}
    
    	RREP(i, total / 2 + 1) {
    		if (dp[n][i] == true) {
    			return total - 2 * i;
    		}
    	}
    
    	return total;
    }

	int minDifference(int arr[], int n)  { 
	    vi vec(arr, arr+n);
	    return minSubsetSumDiff(vec);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends