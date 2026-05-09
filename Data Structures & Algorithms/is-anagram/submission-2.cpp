class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        std::unordered_map<char, int> new_map;
        for (char c : t) {
            new_map[c]++;
        }
        return map == new_map;
    }
};