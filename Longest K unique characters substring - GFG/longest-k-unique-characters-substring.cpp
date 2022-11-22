//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int n = s.length();
        
        int mp[256] = {0};
        int unq = 0, res = -1;
        
        for (int i = 0, j = 0; j < n; ++j) {
            if (unq > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) --unq;
                i++;
                --j;
                continue;
            }
            mp[s[j]]++;
            if (mp[s[j]] == 1) unq++;
            
            if (unq == k) res = max(res, j - i +1);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends