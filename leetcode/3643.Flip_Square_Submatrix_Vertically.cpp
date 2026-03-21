class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int j = y; j < y + k; ++j) {
            stack<int> st;
            for (int i = x; i < x + k; ++i) {
                st.push(grid[i][j]);
            }
            for (int i = x; i < x + k; ++i) {
                grid[i][j] = st.top(); st.pop();
            }
        }
        return grid;
    }
};
