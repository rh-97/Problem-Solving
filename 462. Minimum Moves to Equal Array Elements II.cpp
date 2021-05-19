// Median
// O(n)


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> :: iterator it = nums.begin() + (n >> 1);
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        
        int moves = 0;
        for (auto &num : nums) moves += abs(num - median);
        
        return moves;
    }
};




