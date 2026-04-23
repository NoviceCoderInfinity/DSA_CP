// Approach 1: Hashmap for Indices + Brute-Force Calculation
// Time Complexity: O(nlogn) + O(n^2) ~ O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (mp[nums[i]].size() == 1) continue;
            long long a = 0;
            for (int t: mp[nums[i]]) {
                if (t == i) continue;
                a += abs(t - i);
            }
            result[i] = a;
        }
        return result;
    }
};

// Approach 2: HashMap + Prefix-sum
// Time Complexity: O(nlogn) + O(n) ~ O(n logn)
// Space Complexity: O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        map<int, vector<long long>> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].push_back(i);
                continue;
            }
            long long tmp = mp[nums[i]].back();
            tmp += i;
            mp[nums[i]].push_back(tmp);
        }

        for (auto& [val, pos]: mp) {
            int k = pos.size();
            for (int i = 0; i < k; ++i) {
                long long idx = pos[i];
                if (i != 0) idx = pos[i] - pos[i-1];
                
                long long left = (long long)i * idx - (i > 0 ? pos[i-1]: 0);
                long long right = (pos[k-1] - pos[i]) - (long long)(k - i - 1) * idx;

                result[idx] = left + right;
            }
        }

        return result;
    }
};
