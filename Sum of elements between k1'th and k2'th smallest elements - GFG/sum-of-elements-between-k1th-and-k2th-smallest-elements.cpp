//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;

class Solution{
    public:
    
    long long kthSmallest(long long A[], long long n, long long k) {
        priority_queue<ll> pq;
        for (ll i = 0; i < n; ++i) {
            pq.push(A[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        ll k1th = kthSmallest(A, N, K1);
        ll k2th = kthSmallest(A, N, K2);
        ll sum = 0;
        for (int i = 0; i < N; ++i) {
            if (k1th < A[i] && A[i] < k2th) {
                sum += A[i];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends