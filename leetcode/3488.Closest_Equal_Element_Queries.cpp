class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[ nums[i] ].push_back(i);
        }

        vector<int> ans;

        for (int q: queries) {
            int val = nums[q];
            auto& vec = mp[val];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int m = vec.size();

            int left = vec[(idx - 1 + m) % m];
            int right = vec[(idx + 1) % m];

            int distLeft = min(abs(q - left), n - abs(q - left));
            int distRight = min(abs(q - right), n - abs(q - right));

            ans.push_back(min(distLeft, distRight));
        }

        return ans;
    }
};
