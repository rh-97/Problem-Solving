//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        list<int> li;
        vector<int> maxx;
        
        for (int i = 0, j = 0; j < n; ++j) {
            
            if (!li.empty() and li.front() < arr[j]) li.clear();
            else while (!li.empty() and li.back() < arr[j]) {
                li.pop_back();
            }
            li.push_back(arr[j]);
            
            if (j - i + 1 < k) continue;
            
            maxx.push_back(li.front());
            
            if (li.front() == arr[i]) li.pop_front();
            i++;
        }
        
        return maxx;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends