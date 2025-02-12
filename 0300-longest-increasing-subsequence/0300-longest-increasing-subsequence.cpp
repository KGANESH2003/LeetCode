class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);  // Initialize dp array with 1
        int res = 1;  // To keep track of the maximum length

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);  // Update the result with the maximum length found
        }

        return res;  // Return the length of the longest increasing subsequence
    }
};
