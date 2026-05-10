class Solution {
   public:
    string longestPalindrome(string s) {
        int pos = 0, len = 0, l, r;
        for (int i = 0; i < s.length(); i++) {
            l = r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    pos = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    pos = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(pos, len);
    }
};