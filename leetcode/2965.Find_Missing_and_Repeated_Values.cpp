// Solution 1: Time Complexity O(n^2) - two O(n^2) loops; Space Complexity O(n^2)
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

// Solution 2: Time Complexity O(n^2) - one O(n^2) loop; Space Complexity O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); int num = 1;
        set<int> elements;
        vector<int> result = {0, 0};
        for (vector<int> v: grid) {
            for (int i = 0; i < n; ++i) {
                result[1] ^= num++; 
                if (elements.find(v[i]) != elements.end()) {
                    result[0] = v[i];
                    continue;
                }
                elements.insert(v[i]);
                result[1] ^= v[i];
            }
        }
        return result;
    }
};
