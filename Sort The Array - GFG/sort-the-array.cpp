//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    void qsort(vector<int>& arr, int L, int R) {
        
        if (L >= R) {
            return;
        }
        
        srand(time(0));
        swap(arr[L], arr[((rand() % (R - L + 1)) + L)]);
        
        int& pivot = arr[L];
        int left = L + 1, right = R;
        
        while (left <= right) {
            while (left <= right && arr[left] <= pivot) {
                left++;
            }
            while (arr[right] > pivot) {
                right--;
            }
            if (left < right) {
                swap(arr[left], arr[right]);
            }
        }
        swap(pivot, arr[right]);
        
        qsort(arr, L, right - 1);
        qsort(arr, right + 1, R);
        
    }
    
    bool isSorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> sortArr(vector<int>& arr, int n){
        if(!isSorted(arr)) {
            qsort(arr, 0, arr.size() - 1);
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends