class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        // dp[i][j] = true if nums[0...i] can form
        // subset sum j
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int half = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(half + 1, false));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= half) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (j - nums[i] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][half];
    }
};