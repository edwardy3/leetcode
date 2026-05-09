class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int e : nums) {
            map[e]++;
        }
        vector<std::pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), comp);
        vector<int> topK;
        for (int i = 0; i < k; i++) {
            topK.push_back(vec[i].first);
        }
        return topK;
    }
private:
    static bool comp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};