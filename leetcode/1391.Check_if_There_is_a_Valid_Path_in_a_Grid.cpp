class Solution {
public:
    vector<vector<int>> dirs = {{0,0,0,0}, {0,1,0,3}, {1,0,2,0}, {0,0,2,3}, {0,1,2,0}, {1,0,0,3}, {1,1,0,0}};
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int pipeType = grid[r][c];
            for (int i = 0; i < 4; i++) {
                if (dirs[pipeType][i]) {
                    int nr = r + dy[i];
                    int nc = c + dx[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        int nextPipe = grid[nr][nc];
                        int backDir = (i + 2) % 4;
                        if (dirs[nextPipe][backDir]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return false;
    }
}
