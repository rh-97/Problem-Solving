class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        
        int maxx = INT_MIN;
        int weak = 0;
        for (auto& p: properties) {
            if (maxx > p[1]) {
                weak++;
            } else {
                maxx = p[1];
            }
        }
        
        return weak;
    }
};