class Solution {
public:
    vector<int> last_zero_count(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zero_count(n, 0);
        for (int row = 0; row < n; ++row) {
            vector<int>& v = grid[row];
            int count = 0;
            for (int col = n-1; col >= 0; --col) {
                if (v[col] != 0) {
                    break;
                }
                ++count;
            }
            zero_count[row] = count;
        }
        return zero_count;
    }

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zero_count = last_zero_count(grid);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            int required = n - 1 - i;
            int j = i;

            while (j < n && zero_count[j] < required) {
                ++j;
            }

            if (j == n) return -1;

            while (j > i) {
                swap(zero_count[j], zero_count[j - 1]);
                --j;
                ++swaps;
            }
        }

        return swaps;
    }
};
