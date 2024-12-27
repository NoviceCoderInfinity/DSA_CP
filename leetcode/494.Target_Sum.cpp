class Solution {
public:
    int total_ways = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        recursion(0, 0, nums, target);
        return total_ways;
    }

private:
    void recursion(int index, int curr_sum, vector<int>& nums, int target) {
        if (index == nums.size()) {
            if (curr_sum == target) {++total_ways;} return;
        }
        recursion(index + 1, curr_sum + nums[index], nums, target);
        recursion(index + 1, curr_sum - nums[index], nums, target);
        return;
    }
};
