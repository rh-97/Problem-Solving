// Map
// O(N * L), N -> Number of paths, L -> Max length of a path

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        parse(paths);
        
        for (auto &[key, vec] : mp) {
            if (vec.size() > 1) res.push_back(vec);
        }
        
        return res;
    }
    
private:
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> res;
    
    void parse(vector<string> &paths) {
        
        for (string &path : paths) {
            
            string dir = "";
            int n = path.length();
            int i = 0;
            
            while (path[i] != ' ') dir += path[i++];
            
            while (i < n) {
                
                string file_name = "";
                string content = "";
                
                while (path[++i] != '(') file_name += path[i];
                
                while (path[++i] != ')') content += path[i];
                
                mp[content].push_back(dir + "/" + file_name);
                
                ++i;
            }
        }
    }
};
