class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0; int dir = 2; // default direction is North and we start from (0, 0)
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; 
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {    obstacleSet.insert({obstacle[0], obstacle[1]}); }
        int max_dist = 0;
        for (int command: commands) {
            if (command == -1) {dir = (dir+1) % 4;}
            else if (command == -2) {--dir; if (dir < 0){dir = 3;}}
            else {
                int dist_mv = command;
                while (dist_mv--) {
                    int next_x = x + directions[dir].first;
                    int next_y = y + directions[dir].second;
                    if (obstacleSet.find({next_x, next_y}) == obstacleSet.end()) {
                        x = next_x; y = next_y;
                        max_dist = max(max_dist, x * x + y * y);} 
                    else { break; }
                }
            }
        }
        return max_dist;
    }
};
