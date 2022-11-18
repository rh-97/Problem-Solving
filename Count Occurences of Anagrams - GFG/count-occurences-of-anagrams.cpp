//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    unordered_map<char, int> mp;
	    for (char& p: pat) mp[p]++;
	    int m = pat.size(), n = txt.size();
	    int unq = mp.size(), ans = 0;
	    
	    for (int i = 0, j = 0; j < n; ++j) {
	        mp[txt[j]]--;
	        if (mp[txt[j]] == 0) unq--;
	        if (mp[txt[j]] == -1) unq++;
	        
	        if (j - i + 1 < m) continue;
	        
	        if (unq == 0) ans++;
	        
	        mp[txt[i]]++;
	        if (mp[txt[i]] == 0) unq--;
	        if (mp[txt[i]] == 1) unq++;
	        i++;
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends