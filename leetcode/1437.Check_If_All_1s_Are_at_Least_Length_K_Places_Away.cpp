class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_k = -k - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - last_k <= k) return false;
                last_k = i;
            }
        }
        return true;
    }
};
