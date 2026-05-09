class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> vec = nums;
        std::sort(vec.begin(), vec.end());
        unordered_map<int, vector<int>> map;
        int latest = 0;
        map[latest].push_back(vec[0]);
        for (int e : vec) {
            vector<int>& v = map[latest];
            if (v[v.size() - 1] + 1 == e) {
                v.push_back(e);
            } else if (v[v.size() - 1] == e) {
                continue;
            } else {
                latest++;
                map[latest] = vector<int>{e};
            }
        }
        int longest = 0;
        for (auto& pair : map) {
            if (pair.second.size() > longest) {
                longest = pair.second.size();
            }
        }
        return longest;
    }
};