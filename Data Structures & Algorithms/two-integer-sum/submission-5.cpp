class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(nums[i]);
            if (it != map.end()) {
                return std::vector<int>{it->second, i};
            } else {
                map.insert(std::make_pair(target - nums[i], i));
            }
        }
        return std::vector<int>{};
    }
};