class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        if (n == 0) return "";
        int start = 0, max_len = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {dp[i][i] = true;}
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                max_len = 2;
            }
        }

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i; max_len = len;
                }
            }
        }

        return s.substr(start, max_len);
    }
};
