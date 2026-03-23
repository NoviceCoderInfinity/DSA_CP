// DP
// Time Complexity: O(mn)
// Space Complexity: O(mn)
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> max_prod = vector<vector<long long>>(m, vector<long long>(n));
        vector<vector<long long>> min_prod = vector<vector<long long>>(m, vector<long long>(n));

        long long MOD = 1e9 + 7;
        max_prod[0][0] = min_prod[0][0] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                vector<long long> candidates;

                if (i > 0) {
                    candidates.push_back(max_prod[i-1][j] * grid[i][j]);
                    candidates.push_back(min_prod[i-1][j] * grid[i][j]);
                }
                if (j > 0) {
                    candidates.push_back(max_prod[i][j-1] * grid[i][j]);
                    candidates.push_back(min_prod[i][j-1] * grid[i][j]);
                }

                max_prod[i][j] = *max_element(candidates.begin(), candidates.end());
                min_prod[i][j] = *min_element(candidates.begin(), candidates.end());
            }
        }

        if (max_prod[m-1][n-1] < 0) return -1;
        return max_prod[m-1][n-1]%MOD;
    }
};
