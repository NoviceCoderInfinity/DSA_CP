// Brute Force
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                bool repeat = false;
                for (int i_ = 0; i_ < m; ++i_) {
                    if (i == i_) {
                        continue;
                    }

                    if (mat[i_][j] == 1) {repeat = true; break;}
                }
                if (!repeat) {
                    for (int j_ = 0; j_ < n; ++j_) {
                        if (j == j_) {
                            continue;
                        }
                        if (mat[i][j_] == 1) {repeat = true; break;}
                    }
                }
                count += (!repeat);
            }
        }
        return count;
    }
};

// Optimized Solution
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        int row_one_count = 0;
        int col_one_count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                row_count[i]++;
                if (row_count[i] == 1) {
                    ++row_one_count;
                } else if (row_count[i] > 1) {
                    --row_one_count;
                }
                col_count[j]++;
                if (col_count[j] == 1) {
                    ++col_one_count;
                } else if (col_count[j] > 1) {
                    --col_one_count;
                }
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                count += (
                    mat[row][col] == 1 &&
                    row_count[row] == 1 && 
                    col_count[col] == 1
                );
            }
        }
        
        return count;
    }
};
