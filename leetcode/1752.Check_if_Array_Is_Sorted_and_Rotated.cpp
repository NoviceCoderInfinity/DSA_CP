class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() < 3) {return true;}
        bool inversion = false; int inversion_index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= nums[i-1]) {continue;}
            else {
                if (inversion == true) {return false;}
                else {inversion = true; inversion_index = i;}
            }
        }
        if (inversion == true && nums.back() <= nums.front()) {return true;}
        if (inversion == false) {return true;}
        return false;
    }
};
