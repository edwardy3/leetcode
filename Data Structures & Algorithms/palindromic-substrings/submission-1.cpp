class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, l, r;
        for (int i = 0; i < s.length(); i++) {
            l = r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};