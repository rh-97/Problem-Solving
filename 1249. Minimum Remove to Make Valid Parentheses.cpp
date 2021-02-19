/* PROBLEM STATEMENT 

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.
   Hint #1  
Each prefix of a balanced parentheses has a number of open parentheses greater or equal than closed parentheses, similar idea with each suffix.
   Hint #2  
Check the array from left to right, remove characters that do not meet the property mentioned above, same idea in backward way.

*/

// SOLUTION
// O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> S; // to store indices of characters to be removed
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') S.push(i); //this '(' is to be removed unless a ')' pairs with it
            else if (s[i] == ')') {
                if (S.empty() or s[S.top()] == ')') { // ')' needs to be removed as it can't be paired with a '('
                    S.push(i);
                } else S.pop();   // s[i] == '('  --> '(' and ')' balance each-other 
            } 
        }
        while (!S.empty()) { // erasing selected characters
            s.erase(s.begin() + S.top());
            S.pop();
        }
        return s;
    }
};


