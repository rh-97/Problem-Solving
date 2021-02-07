/* PROBLEM STATEMENT

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the shortest distance from s[i] to the character c in s.

 

Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]
 

Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
c occurs at least once in s.

*/


// O(n)

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res;
        int prev = INT_MIN / 2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) prev = i;
            res.push_back(i - prev);
        }
        prev = INT_MAX / 2;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) prev = i;
            res[i] = min(res[i], prev - i);
        }
        return res;
    }
};





// EXPLANATION

// Min Array [Accepted]
// Intuition

// For each index S[i], let's try to find the distance to the next character C going left, and going right. The answer is the minimum of these two values.

// Algorithm

// When going left to right, we'll remember the index prev of the last character C we've seen. Then the answer is i - prev.

// When going right to left, we'll remember the index prev of the last character C we've seen. Then the answer is prev - i.

// We take the minimum of these two answers to create our final answer.

