class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col_sz = strs.front().size();
        vector<bool> to_remove(col_sz, false);
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < col_sz; ++j) {
                if (to_remove[j] == true) {continue;}
                to_remove[j] = !(strs[i][j] >= strs[i-1][j]);
            }
        }
        int count = 0;
        for (bool rm: to_remove) {count += static_cast<int>(rm);}
        return count;
    }
};
