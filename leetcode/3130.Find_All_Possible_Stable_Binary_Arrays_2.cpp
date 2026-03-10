class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector dp(zero+1, vector<array<int,2>>(one+1, {0,0}));

        for (int z = 1; z <= min(zero, limit); z++)
            dp[z][0][0] = 1;

        for (int o = 1; o <= min(one, limit); o++)
            dp[0][o][1] = 1;

        for (int z = 1; z <= zero; z++) {
            for (int o = 1; o <= one; o++) {

                long long val0 =
                    (dp[z-1][o][0] + dp[z-1][o][1]) % MOD;

                if (z - limit - 1 >= 0)
                    val0 = (val0 - dp[z-limit-1][o][1] + MOD) % MOD;

                dp[z][o][0] = val0;

                long long val1 =
                    (dp[z][o-1][0] + dp[z][o-1][1]) % MOD;

                if (o - limit - 1 >= 0)
                    val1 = (val1 - dp[z][o-limit-1][0] + MOD) % MOD;

                dp[z][o][1] = val1;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
