class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int, int> mp;

        for (int num: nums) {
            mp[num] += 1;
        }

        for (auto const& [key, val]: mp) {
            if (val > 1) return key;
        }
        
        return -1;
    }
};
