//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        
        int n = s.length();
        
        int mp[256] = {0};
        int rpt = 0, res = 1;
        
        for (int i = 0, j = 0; j < n; ++j) {
            if (rpt > 0) {
                mp[s[i]]--;
                if (mp[s[i]] == 1) --rpt;
                i++;
                --j;
                continue;
            }
            if (mp[s[j]] == 1) rpt++;
            mp[s[j]]++;
            
            if (rpt == 0) res = max(res, j - i +1);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends