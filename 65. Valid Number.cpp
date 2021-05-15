// if
// O(n)

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        
        //bool valid = false;
        bool point = false;
        bool E = false;
        bool num = false;
        
        for (int i = 0; i < n; ++i) {
            
            
            switch(s[i]) {
                    
                case '.':
                    if (point or E) return false;
                    point = true;
                    break;
                
                case 'e':
                case 'E':
                    if (E or !num) return false;
                    E = true;
                    num = false;
                    break;
                    
                case '+':
                case '-':
                    if (i != 0 and s[i - 1] != 'E' and s[i - 1] != 'e') return false;
                    break;
                
                default:
                    if (s[i] < '0' or '9' < s[i]) return false;
                    num = true;
            }    
        }
            
        return num;
        
    }
};



