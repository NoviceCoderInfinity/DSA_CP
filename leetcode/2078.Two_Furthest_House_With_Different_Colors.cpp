class Solution {
public:
    int maxDistance(vector<int>& colors) {
        map<int, pair<int, int>> mp;
        for (int i = 0; i < colors.size(); ++i) {
            if (mp.find(colors[i]) == mp.end()) {
                mp[colors[i]] = {i, i};
            } else {
                mp[colors[i]].second = i;
            }
        }

        int max_dist = 0;

        for (auto& [c1, p1]: mp) {
            for (auto& [c2, p2]: mp) {
                if (c1 != c2) {
                    max_dist = max(max_dist, abs(p1.first - p2.second));
                    max_dist = max(max_dist, abs(p2.first - p1.second));
                }
            }
        }

        return max_dist;
    }
};
