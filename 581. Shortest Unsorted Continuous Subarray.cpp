/* PROBLEM STATEMENT 

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?

*/

// SOLUTION

// Sorting 
// O(n log n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int n = nums.size();
        int l = -1, r = n - 1;
        for (int i = 0; i < n; ++i){
            if (nums[i] != copy[i]) {
                l = i;
                break;
            }
        }
        if (l == -1) return 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] != copy[i]) {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};


// From Leetcode Solutions - 'Approach 5: Without Using Extra Space'
// MinMax
// O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minn = INT_MAX, maxx = INT_MIN;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                minn = min(minn, nums[i]);
        }
        flag = false;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                maxx = max(maxx, nums[i]);
        }
        int l, r;
        for (l = 0; l < n; l++) {
            if (minn < nums[l])
                break;
        }
        for (r = n - 1; r >= 0; r--) {
            if (maxx > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
};
