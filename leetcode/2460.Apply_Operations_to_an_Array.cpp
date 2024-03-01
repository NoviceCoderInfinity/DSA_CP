// Solution 1
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2; nums[i+1] = 0; ++i;
            }
        }
        
        int insert = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {nums[insert++] = nums[i];}
        }

        while(insert < nums.size()) {
            nums[insert++] = 0;
        }
        return nums;
    }
};

// Solution 2
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int insert = 0, i = 0;
        for ( ; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2; nums[i+1] = 0;
            }

            if (nums[i]) {
                if (i != insert) {swap(nums[i], nums[insert]);}
                ++insert;
            }
        }

        if (nums[i]) {
            if (i != insert) {swap(nums[i], nums[insert]);}
            ++insert;
        }
        return nums;
    }
};
