class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Input: nums = [9,1,4,2,3,3,7]
        // Output: 4
        // dp[i] = length of LIS whose first element must be nums[i]
        // exploits the fact that every LIS must start at least somewhere
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i=n-1; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
                if (nums[i]<nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};