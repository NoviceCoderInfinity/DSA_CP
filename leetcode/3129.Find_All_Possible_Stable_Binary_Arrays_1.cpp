class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector dp(zero+1,
            vector(one+1,
                vector(2,
                    vector<int>(limit+1,0)))); // zero, one, last element, consecutive
        const int MOD = 1e9 + 7;

        if (zero) dp[1][0][0][1] = 1;
        if (one) dp[0][1][1][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                for (int last = 0; last < 2; last++) {
                    for (int c = 1; c <= limit; c++) {
                        int ways = dp[z][o][last][c];
                        if (ways == 0) continue;

                        if (z < zero) {
                            if (last == 0) {
                                if (c + 1 <= limit) {
                                    dp[z+1][o][0][c+1] = (dp[z+1][o][0][c+1] + ways) % MOD;
                                }
                            }
                            else {
                                dp[z+1][o][0][1] = (dp[z+1][o][0][1] + ways) % MOD;
                            }
                        }
                        if (o < one) {
                            if (last == 1) {
                                if (c + 1 <= limit) {
                                    dp[z][o+1][1][c+1] = (dp[z][o+1][1][c+1] + ways) % MOD;
                                }
                            } else {
                                dp[z][o+1][1][1] = (dp[z][o+1][1][1] + ways) % MOD;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;

        for (int last = 0; last < 2; last++) {
            for (int c = 1; c <= limit; c++) {
                ans = (ans + dp[zero][one][last][c]) % MOD;
            }
        }

        return ans;
    }
};
