class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec(nums.size(), 1);
        int prefix = 1, suffix = 1;
        for (int forward = 0; forward < nums.size(); forward++) {
            vec[forward] *= prefix;
            prefix *= nums[forward];
            int backward = nums.size() - (forward + 1);
            vec[backward] *= suffix;
            suffix *= nums[backward];
        }
        return vec;
    }
};