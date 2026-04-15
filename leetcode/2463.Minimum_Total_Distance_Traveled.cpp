class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory, dp);
    }

    long long solve(int i, int j,
                    vector<int>& robot,
                    vector<vector<int>>& factory,
                    vector<vector<long long>>& dp) {

        if (i == robot.size()) return 0;
        if (j == factory.size()) return 1e12;

        if (dp[i][j] != -1) return dp[i][j];

        long long res = solve(i, j + 1, robot, factory, dp);
        long long cost = 0;
        int pos = factory[j][0];
        int cap = factory[j][1];

        for (int k = 1; k <= cap && i + k - 1 < robot.size(); k++) {
            cost += abs(robot[i + k - 1] - pos);
            res = min(res, cost + solve(i + k, j + 1, robot, factory, dp));
        }

        return dp[i][j] = res;
    }
};
