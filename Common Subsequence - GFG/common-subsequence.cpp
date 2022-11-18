//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool commonSubseq (string s, string t)
	{
	    int n = s.length(), m = t.length();
		    
	    vector<int> freq(256);
	    
	    for (char& c: s) freq[c]++;
	    
	    for (char& c: t) if (freq[c] > 0) return true;
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends