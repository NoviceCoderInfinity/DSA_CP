class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        set<int> cols, diag1, diag2;
        vector<int> pos(n, -1);
        vector<int> next_col(n, 0);

        int i = 0;

        while (i >= 0) {
            bool is_psbl = false;
            int j = next_col[i];
            while (!is_psbl && j < n) {
                if (cols.count(j) || diag1.count(i-j) || diag2.count(i+j)) {
                    ++j;
                    continue;
                }
                cols.insert(j);
                diag1.insert(i-j);
                diag2.insert(i+j);

                pos[i] = j;
                next_col[i] = j+1;

                is_psbl = true;
                ++i;
            }

            if (!is_psbl) { // backtrack
                next_col[i] = 0;
                --i;

                if (i >= 0) {
                    int j = pos[i];
                    cols.erase(j);
                    diag1.erase(i-j);
                    diag2.erase(i+j);
                    continue;
                }
            }

            if (i == n) {
                vector<string> board(n, string(n, '.'));
                for (int r = 0; r < n; ++r)
                    board[r][pos[r]] = 'Q';
                result.push_back(board);

                --i;
                int j = pos[i];
                cols.erase(j);
                diag1.erase(i-j);
                diag2.erase(j+i);
            }
        }

        return result;
    }
};
