class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, 0));
        if (k < 2) return res;
        for (int i = 0; i <= m - k; ++i) {
            multiset<int> ele;
            for (int j = 0; j <= n - k; ++j) {
                if (j > 0) {
                    for (int t = i; t < i + k; ++t) {
                        auto it = ele.find(grid[t][j-1]);
                        ele.erase(it);
                    }
                }
                if (j == 0) {
                    for (int x = i; x < i + k; ++x) {
                        for (int y = j; y < j + k; ++y) {
                            ele.insert(grid[x][y]);
                        }
                    }
                } else {
                    for (int t = i; t < i + k; ++t) {
                        ele.insert(grid[t][j + k - 1]);
                    }
                }
                int ans = INT_MAX;
                for (auto it = next(ele.begin()); it != ele.end(); ++it) {
                    if (*it == *prev(it)) continue;
                    ans = min(ans, *it - *prev(it));
                }
                res[i][j] = (ans == INT_MAX ? 0 : ans);
            }
        }
        return res;
    }
};
