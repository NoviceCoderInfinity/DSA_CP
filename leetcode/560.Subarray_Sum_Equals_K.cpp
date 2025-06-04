// Solution 1
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0; int j = i; bool is_empty = true;
            while (j < nums.size()) {
                sum += nums[j];
                ++j; is_empty = false;
                if ((sum == k) && !is_empty) {++count;}
            }
        }
        return count;
    }
};
