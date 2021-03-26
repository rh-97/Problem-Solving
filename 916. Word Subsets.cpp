// Intuitive
// O(NA * Na + NB * Nb), NA -> length of A, Na -> maxlength of a string in A, NB -> length of B, Nb -> max length of a string in B
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> maxx(26);
        for (string b : B) {
            vector<int> temp = countChars(b);
            for (int i = 0; i < 26; ++i) maxx[i] = max(maxx[i], temp[i]);
        }
        vector<string> universal;
        for (string a : A) {
		        vector<int> temp = countChars(a);
            if (is_subset(temp, maxx)) universal.push_back(a);
        }
        return universal;
    }
    
    vector<int> countChars(const string &s) {
        vector<int> res(26);
        for (char c : s) ++res[c - 'a'];
        return res;
    }
    bool is_subset(const vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < 26; ++i) if (b[i] > a[i]) return false;
        return true;
    }
};



