// Solution 1: Brute Force Solution
// Time Complexity: O(m^2 * n^2)
// Space Complexity: O(m * n) per DFS call
class Solution {
public:
    bool reaches_pacific = false; bool reaches_atlantic = false;
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        set<vector<int>> visited;
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                reaches_pacific = false; reaches_atlantic = false;
                DFS(i, j, heights, visited);
                visited.clear();
                if (reaches_pacific && reaches_atlantic) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void DFS(int i, int j, vector<vector<int>>& heights, set<vector<int>>& visited) {
        visited.insert({i, j});
        if (reaches_pacific && reaches_atlantic) {return;}
        if (i == 0 || j == 0) {reaches_pacific = true;}
        if (i == m-1 || j == n-1) {reaches_atlantic = true;}
        if ((i > 0) && (visited.find({i-1, j}) == visited.end()) && (heights[i-1][j] <= heights[i][j])) {
            DFS(i-1, j, heights, visited);
        }
        if ((i < m-1) && (visited.find({i+1, j}) == visited.end()) && (heights[i+1][j] <= heights[i][j])) {
            DFS(i+1, j, heights, visited);
        }
        if ((j > 0) && (visited.find({i, j-1}) == visited.end()) && (heights[i][j-1] <= heights[i][j])) {
            DFS(i, j-1, heights, visited);
        }
        if ((j < n-1) && (visited.find({i, j+1}) == visited.end()) && (heights[i][j+1] <= heights[i][j])) {
            DFS(i, j+1, heights, visited);
        }
        return;
    }
};
