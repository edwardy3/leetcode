class Solution {
   public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        if (s[n - 1] != '0') {
            dp[n - 1] = 1;
        }
        if (n >= 2 && s[n - 2] != '0') {
            dp[n - 2] += dp[n - 1];
            int c = stoi(s.substr(n - 2, 2));
            if (c >= 1 && c <= 26) {
                dp[n - 2]++;
            }
        }
        for (int i = n - 3; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
                int c = stoi(s.substr(i, 2));
                if (c >= 1 && c <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};