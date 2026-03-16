class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int, greater<int>> distinctSums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                distinctSums.insert(grid[i][j]);

                for (int s = 1; ; ++s) {
                    if (i - s < 0 || i + s >= m || j - s < 0 || j + s >= n) break;

                    int currentSum = 0;
                    
                    // Add the four corners: top, bottom, left, right
                    currentSum += grid[i - s][j];
                    currentSum += grid[i + s][j];
                    currentSum += grid[i][j - s];
                    currentSum += grid[i][j + s];
                    
                    for (int k = 1; k < s; ++k) {
                        currentSum += grid[i - s + k][j + k]; // Top to Right
                        currentSum += grid[i + s - k][j + k]; // Bottom to Right
                        currentSum += grid[i - s + k][j - k]; // Top to Left
                        currentSum += grid[i + s - k][j - k]; // Bottom to Left
                    }
                    distinctSums.insert(currentSum);
                }
            }
        }

        vector<int> result;
        for (int sum : distinctSums) {
            result.push_back(sum);
            if (result.size() == 3) break;
        }
        return result;
    }
};
