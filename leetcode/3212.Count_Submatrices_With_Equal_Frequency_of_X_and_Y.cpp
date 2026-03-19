// 2D Prefix Sum Method
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> freq_equalizer(m, vector<int>(n, 0));
        vector<vector<int>> has_X(m, vector<int>(n, false));
        map<char, int> mp = {
            {'X', 1}, 
            {'Y', -1}, 
            {'.', 0}
        };

        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                freq_equalizer[i][j] = mp[ grid[i][j] ];

                freq_equalizer[i][j] += (
                    ((i > 0) ? freq_equalizer[i-1][j] : 0) +
                    ((j > 0) ? freq_equalizer[i][j-1] : 0) +
                    (((i > 0) && (j > 0)) ? -freq_equalizer[i-1][j-1] : 0)
                );

                has_X[i][j] = ((grid[i][j] == 'X')
                               || (i > 0 && has_X[i-1][j])
                               || (j > 0 && has_X[i][j-1]));

                if ((freq_equalizer[i][j] == 0) && has_X[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
