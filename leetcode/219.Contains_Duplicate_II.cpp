// Brute-Force
// Time Complexity: O(nk)
// Space Complexity: O(1)
// Result: Accepted
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {return true;}
            }
        }

        return false;
    }
};


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
