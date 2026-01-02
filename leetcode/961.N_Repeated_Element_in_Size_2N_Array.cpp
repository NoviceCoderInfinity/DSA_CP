// Hash Set
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int, int> mp;

        for (int num: nums) {
            mp[num] += 1;
        }

        for (auto const& [key, val]: mp) {
            if (val > 1) return key; // for N duplicates in 2N array, there must be N unique, so any duplicate is the answer
        }
        
        return -1;
    }
};

// Sorting based approach
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() / 2;
        if (nums[mid] != nums[mid+1]) {return nums[mid-1];}
        return nums[mid];
    }
};
