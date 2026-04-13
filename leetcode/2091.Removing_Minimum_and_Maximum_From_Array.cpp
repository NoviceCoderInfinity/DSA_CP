class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx = -1, max_idx = -1;
        int min_val = INT_MAX, max_val = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > max_val) {
                max_idx = i;
                max_val = num;
            } if (num < min_val) {
                min_idx = i;
                min_val = num;
            }
        }

        int left_most = min(min_idx, max_idx);;
        int right_most = max(min_idx, max_idx);

        if (left_most == right_most) {
            return min(left_most + 1, static_cast<int>(nums.size() - right_most));
        }
        else {
            int v1 = left_most + 1 + (nums.size() - right_most);
            int v2 = right_most + 1;
            int v3 = nums.size() - left_most;
            return min(v1, min(v2, v3));
        }

        return -1;
    }
};
