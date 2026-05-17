class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // max product of all subarrays ending at index i
        int maximum = nums[0], minimum = nums[0], glob = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp_max = maximum;
            maximum = max({nums[i], maximum*nums[i], minimum*nums[i]});
            minimum = min({nums[i], temp_max*nums[i], minimum*nums[i]});
            if (maximum > glob) {
                glob = maximum;
            }
        }
        return glob;
    }
};