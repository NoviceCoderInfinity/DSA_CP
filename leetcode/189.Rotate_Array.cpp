class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> prefix_arr(nums.begin() + nums.size() - k, nums.begin() + nums.size());
        vector<int> suffix_arr(nums.begin(), nums.end() - k);
        nums.clear();
        nums.insert(nums.end(), prefix_arr.begin(), prefix_arr.end());
        nums.insert(nums.end(), suffix_arr.begin(), suffix_arr.end());
    }
};
