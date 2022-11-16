//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool is_valid(int A[], int mx, int m, int n) {
        int sum = 0, students = 1;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            if (sum > mx) {
                sum = A[i];
                students++;
            }
            if (students > m) {
                return false;
            }
        }
        return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if (M > N) return -1;
        
        int mx = *max_element(A, A+N);
        int sum = accumulate(A, A+N, 0);
        int res = -1;
        
        int left = mx, right = sum, mid;
        while (left <= right) {
            
            mid = left + ((right - left) >> 1);
            
            if (is_valid(A, mid, M, N)) {
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends