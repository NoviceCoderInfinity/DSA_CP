// Brute Force Solution
// Time Complexity: O(nk)
// Space Complexity: O(1)
// Result: Rejected
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + indexDiff && j < nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) <= valueDiff) {
                    return true;
                }
            }
        }
        return false;
    }
};
