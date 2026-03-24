class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long MOD = 12345;
        
        vector<vector<int>> prefix = grid;
        vector<vector<int>> suffix = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    if (i > 0) {
                        prefix[i][j] = (prefix[i-1][m-1])%MOD * (prefix[i][j])%MOD;
                    }
                } else {
                    prefix[i][j] = (prefix[i][j-1])%MOD * (prefix[i][j])%MOD;
                }
            }
        }

        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (j == m-1) {
                    if (i < n-1) {
                        suffix[i][j] = (suffix[i+1][0])%MOD * (suffix[i][j])%MOD;
                    }
                } else {
                    suffix[i][j] = (suffix[i][j+1])%MOD * (suffix[i][j])%MOD;
                }
            }
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long left = 1, right = 1;
                
                if (!(i == 0 && j == 0)) {
                    if (j == 0) {
                        left = prefix[i-1][m-1];
                    } else {
                        left = prefix[i][j-1];
                    }
                }

                if (!(i == n-1 && j == m-1)) {
                    if (j == m-1) {
                        right = suffix[i+1][0];
                    } else {
                        right = suffix[i][j+1];
                    }
                }

                res[i][j] = (left * right) % MOD;
            }
        }
        
        return res;
    }
};
