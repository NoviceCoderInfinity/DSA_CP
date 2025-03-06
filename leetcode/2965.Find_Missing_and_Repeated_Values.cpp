// Solution 1
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> elements_frequency(n*n, 1);
        for (vector<int> v: grid) {
            for (int i = 0; i < n; ++i) {
                --elements_frequency[v[i]-1];
            }
        }
        vector<int> result = {0, 0};
        for (int i = 0; i < n*n; ++i) {
            if (elements_frequency[i] == -1) {result[0] = i + 1;}
            else if (elements_frequency[i] == 1) {result[1] = i + 1;}
        }
        return result;
    }
};
