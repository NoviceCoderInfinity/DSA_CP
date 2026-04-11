class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]].push_back(i);

        int min_dist = INT_MAX;

        for (auto &entry : mp) {
            auto &v = entry.second;
            if (v.size() < 3) continue;

            for (int i = 0; i + 2 < v.size(); ++i)
                min_dist = min(min_dist, 2 * (v[i + 2] - v[i]));
        }

        return min_dist == INT_MAX ? -1 : min_dist;
    }
};

