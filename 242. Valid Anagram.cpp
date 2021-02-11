/* PROBLEM STATEMENT

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
/*

// O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }
        for (int f: freq) if (f) return false;
        return true;
    }
};



