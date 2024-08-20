class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {return nums.size();}
        int left = 0; int right = 0;  
        while(right < nums.size() ) {
            while(right < nums.size() && nums[right] == nums[left]) {++right;}
            if (right >= nums.size()) {break;} 
            ++left; nums[left] = nums[right];
        }
        return left + 1;
    }
};
