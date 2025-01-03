class Solution {
public:
    int sum_arr (vector<int>& nums, int divisor) {
        int sum = 0; for (int i = 0; i < nums.size(); ++i) {
            sum += ceil((double)nums[i] / divisor);}
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element (nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sum_arr(nums, mid) <= threshold) {high = mid - 1;}
            else {low = mid + 1;}
        }
        return low;
    }
};
