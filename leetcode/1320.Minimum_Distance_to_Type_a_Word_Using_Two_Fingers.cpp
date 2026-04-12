class Solution {
public:
    int get_dist_chars(int p, int q) {
        int x_p = p / 6, y_p = p % 6;
        int x_q = q / 6, y_q = q % 6;
        return abs(x_p - x_q) + abs(y_p - y_q);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26, 1e9)));

        // initialization
        for (int i = 0; i < 26; ++i) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }

        // calculating
        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = get_dist_chars(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = get_dist_chars(k, cur);
                        dp[i][cur][j] =
                            min(dp[i][cur][j], dp[i - 1][k][j] + d0);
                        dp[i][j][cur] =
                            min(dp[i][j][cur], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }

        int ans = 1e9;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
    }
};
