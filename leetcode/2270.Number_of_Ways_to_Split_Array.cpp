// Solution 1
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ways_split = 0, n = nums.size();

        long long int left_sum = 0, right_sum = 0;
        for (int num: nums) {
            right_sum += static_cast<long long int>(num);
        }

        for (int i = 0; i < n - 1; ++i) {
            left_sum += static_cast<long long int>(nums[i]);
            right_sum -= static_cast<long long int>(nums[i]);
            ways_split += (left_sum >= right_sum);
        }

        return ways_split;
    }
};

// Solution 2
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ways_split = 0, n = nums.size();

        long long int sum = 0;
        for (int num: nums) {
            sum += static_cast<long long int>(num);
        }

        long long int curr_sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            curr_sum += static_cast<long long int>(nums[i]);
            ways_split += (curr_sum >= sum - curr_sum);
        }

        return ways_split;
    }
};

// Solution 3
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ways_split = 0, n = nums.size();

        vector<long long int> prefix_sum(n, 0);
        prefix_sum[0] = static_cast<long long int>(nums[0]);

        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + static_cast<long long int>(nums[i]);
        }

        for (int i = 0; i < n - 1; ++i) {
            ways_split += (prefix_sum[i] >= prefix_sum.back() - prefix_sum[i]);
        }

        return ways_split;
    }
};
