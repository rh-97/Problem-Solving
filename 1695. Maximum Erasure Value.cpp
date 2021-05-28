// Two Pointers
// O(n)


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxx = 0;
        int sum = 0;
        unordered_set<int> S;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; ++r) {
            if (S.count(nums[r])) maxx = max(maxx, sum);
            while (S.count(nums[r])) {
                S.erase(nums[l]);
                sum -= nums[l];
                ++l;
            }
            sum += nums[r];
            S.insert(nums[r]);
        }
        return max(maxx, sum);
    }
};






