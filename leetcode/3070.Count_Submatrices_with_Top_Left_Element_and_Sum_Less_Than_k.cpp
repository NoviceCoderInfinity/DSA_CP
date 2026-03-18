class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> prefix_sum = grid;
        int rows = grid.size(), cols = grid[0].size();

        int count = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row > 0) prefix_sum[row][col] += prefix_sum[row-1][col];
                if (col > 0) prefix_sum[row][col] += prefix_sum[row][col-1];
                if ((row > 0) && (col > 0)) prefix_sum[row][col] -= prefix_sum[row-1][col-1];

                if (prefix_sum[row][col] <= k) {
                    ++count;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
