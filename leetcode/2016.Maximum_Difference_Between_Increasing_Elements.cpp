// Solution 1: One Pass
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Result: Accepted
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff = -1;
        int min_element = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < min_element) {min_element = nums[i];}
            else if ((nums[i] > min_element) && (nums[i] - min_element > max_diff)) {
                max_diff = nums[i] - min_element;
            }
        }
        return max_diff;
    }
};
