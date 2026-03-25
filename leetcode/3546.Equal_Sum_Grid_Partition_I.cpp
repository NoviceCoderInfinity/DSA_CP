// Approach: 2D Prefix and Suffix Array Sum
// Time Complexity: O(mn)
// Space Complexity: O(mn)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> row_sum(m, 0), col_sum(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_sum[i] += grid[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                col_sum[j] += grid[i][j];
            }
        }

        vector<long long> axis_0_prefix_sum(m, 0), axis_0_suffix_sum(m, 0);
        axis_0_prefix_sum[0] = row_sum.front();
        for (int j = 1; j < m; ++j) {
            axis_0_prefix_sum[j] = axis_0_prefix_sum[j-1] + row_sum[j];
        }
        axis_0_suffix_sum[m - 1] = row_sum.back();
        for (int j = m - 2; j >= 0; --j) {
            axis_0_suffix_sum[j] = axis_0_suffix_sum[j+1] + row_sum[j];
        }

        vector<long long> axis_1_prefix_sum(n, 0), axis_1_suffix_sum(n, 0);
        axis_1_prefix_sum[0] = col_sum.front();
        for (int i = 1; i < n; ++i) {
            axis_1_prefix_sum[i] = axis_1_prefix_sum[i-1] + col_sum[i];
        }
        axis_1_suffix_sum[n - 1] = col_sum.back();
        for (int i = n - 2; i >= 0; --i) {
            axis_1_suffix_sum[i] = axis_1_suffix_sum[i+1] + col_sum[i];
        }

        for (int i = 0; i < n + 1; ++i) {
            long long left_sum, right_sum;
            left_sum = (i == 0) ? 0 : axis_1_prefix_sum[i-1];
            right_sum = (i == n) ? 0 : axis_1_suffix_sum[i];
            if (left_sum == right_sum) return true;
        }

        for (int j = 0; j < m + 1; ++j) {
            long long left_sum, right_sum;
            left_sum = (j == 0) ? 0 : axis_0_prefix_sum[j-1];
            right_sum = (j == m) ? 0 : axis_0_suffix_sum[j];
            if (left_sum == right_sum) return true;
        }

        return false;
    }
};


// Approach: Optimised Sum comparison
// Time Complexity: O(mn)
// Space Complexity: O(1)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        for (auto &row: grid) {
            for (int x: row) {
                total += x;
            }
        }

        if (total % 2) return false;
        
        long long target = total / 2, sum = 0;

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        sum = 0;

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        return false;
    }
};
