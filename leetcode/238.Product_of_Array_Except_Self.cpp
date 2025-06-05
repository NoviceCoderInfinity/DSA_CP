// Solution
// Time Complexity: O(n) + O(n)
// Space Complexity: O(n) or maybe O(1) since it's required to construct an array
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_index; int prod = 1; int zero_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {prod *= nums[i];}
            else {zero_index = i; ++zero_count;}
        }

        vector<int> result(nums.size(), 0);
        if (zero_count == 0) {
            for (int i = 0; i < nums.size(); ++i) {
                result[i] = prod / nums[i];
            }
        }
        else if (zero_count == 1) {
            for (int i = 0; i < nums.size(); ++i) {
                if (zero_index != i) {continue;}
                else{result[i] = prod;}
            }
        }

        return result;
    } 
};
