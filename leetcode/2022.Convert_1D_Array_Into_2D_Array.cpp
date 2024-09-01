class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {return {};}
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int row_iter = 0; row_iter < m; ++row_iter) {
            for (int col_iter = 0; col_iter < n; ++col_iter) {
                matrix[row_iter][col_iter] = original[row_iter * n + col_iter];
            }
        }
        return matrix;
    }
};
