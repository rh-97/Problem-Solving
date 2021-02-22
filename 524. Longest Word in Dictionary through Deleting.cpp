/* PROBLEM STATEMENT

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.

*/

// SOLUTION
// Sorting & Compare
// O(xn log n + mn)

class Solution {
public:
    bool f(string& s, string& d) { // O(m)
        int m = s.size();
        int l = d.size();
        int i = 0, k = 0;
        while (i < m) {
            if (s[i] == d[k]) ++k;
            if (k == l) return true;
            ++i;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(),  [] (const string& first, const string& second) {                  // O(xn log n) - each comparison can be of x operations 
            return first.size() != second.size() ? first.size() > second.size() : first < second;   // where x is the avg length of string in dictionary
        });
        int n = d.size();
        for (int i = 0; i < n; ++i) {     // O(mn)  
            if (f(s, d[i])) return d[i];
        }
        return "";
    }
};


