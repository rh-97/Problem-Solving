//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    
	   // if (n == 1) return arr[0];
	    
	    int left = 0, right = n - 1, mid;
	    
	    while (left <= right) {
	        mid = left +((right - left) >> 1);
	        
	        if (mid > 0 and mid < n - 1) {
	            if (arr[mid] > arr[mid-1] and arr[mid+1] < arr[mid]) {
	                return arr[mid];
	            } else if (arr[mid] > arr[mid-1]) {
	                left = mid + 1;
	            } else {
	                right = mid - 1;
	            }
	        } else if (mid == 0) {
	            left = mid + 1;
	        } else {
	            if (arr[mid] > arr[mid-1]) {
	                return arr[mid];
	            } else {
	                right = mid - 1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends