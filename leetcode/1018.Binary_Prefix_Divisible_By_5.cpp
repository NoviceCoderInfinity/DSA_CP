class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int value = 0;
        vector<bool> results (nums.size(), false);
        for (int i = 0; i < nums.size(); ++i) {
            value *= 2;
            value += nums[i];
            if (value % 5 == 0) results[i] = true;
            value = value % (long)1E9;
        }
        return results;
    }
};
