/* PROBLEM STATEMENT

Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

*/


// SOLUTION
// Intuitive Implementation - calculating for each innermost/central parentheses '()'
// O(n)

class Solution { 
public:
    int scoreOfParentheses(string S) {
        int n = S.size();
        int score = 0, layers = 0;  
        for (int i = 0; i < n; ++i) {
            if (S[i] == '(') ++layers;
            else {
                --layers;
                if (S[i - 1] == '(') score += 1 << layers; // score = score + pow(2, balance) -> for every innermost layer of parentheses '()'
            }
        }
        return score;
    }
};

