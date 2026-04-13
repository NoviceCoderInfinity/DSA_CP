class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for (int step = 0; step < n; ++step) {
            if ((start + step < n && nums[start + step] == target) || 
            (start - step >= 0 && nums[start-step] == target)) return step;
        }
        return -1;
    }
};
