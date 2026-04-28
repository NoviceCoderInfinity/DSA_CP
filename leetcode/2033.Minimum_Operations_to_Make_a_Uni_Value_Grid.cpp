class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> arr;
        int rem = grid[0][0] % x;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr.push_back(grid[i][j] / x);
                if (rem != (grid[i][j]%x)) return -1;
            }
        }

        sort(arr.begin(), arr.end());
        int med = arr[arr.size() / 2];

        int ops = 0;
        for (int val: arr) {
            ops += abs(med - val);
        }

        return ops;
    }
}
