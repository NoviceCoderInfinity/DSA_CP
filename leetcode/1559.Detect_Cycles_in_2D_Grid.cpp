class Solution {
public:
    vector<int> dRow = { -1, 0, 1, 0 };
    vector<int> dCol = { 0, 1, 0, -1 };
    int m, n;

    bool bfs(pair<int,int> start, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({start, {-1, -1}});
        
        visited[start.first][start.second] = true;

        while (!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            auto [x, y] = curr;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dRow[d];
                int ny = y + dCol[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] != grid[x][y]) continue;

                if (visited[nx][ny]) {
                    if (make_pair(nx, ny) != parent) return true;
                } else {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, {x, y}});
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pair<int, int> last;

        queue<pair<int, int>> q;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (!visited[row][col]) {
                    if (bfs({row, col}, visited, grid)) return true;
                }
            }
        }

        return false;
    }
}
