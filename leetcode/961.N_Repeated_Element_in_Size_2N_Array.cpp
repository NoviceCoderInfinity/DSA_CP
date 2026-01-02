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

// Compare based approach, the core idea is for N duplicacy, the maximum distance that can be there between any two duplicated elements is 4
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i >= 1 && (nums[i] == nums[i-1])) return nums[i];
            if (i >= 2 && (nums[i] == nums[i-2])) return nums[i];
            if (i >= 3 && (nums[i] == nums[i-3])) return nums[i];
        }

        return -1;
    }
};
