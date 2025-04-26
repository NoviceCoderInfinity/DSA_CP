// Linear Solution by Hashing
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }

        for (const auto& [num, indices] : mp) {
            for (int j = 1; j < indices.size(); ++j) {
                if (indices[j] - indices[j - 1] <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};
