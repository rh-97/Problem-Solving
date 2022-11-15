//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        int left = 0, right = n - 1, res = -1, mid;
        
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            
            if (a[mid] == 1) {
                res = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return res;
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

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends