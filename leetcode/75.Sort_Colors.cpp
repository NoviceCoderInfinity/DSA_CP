// Solution: Count the frequency of each color and over-write the array
// Time Complexity: O(N) + O(N) (two pass)
// Space Complexity: O(1), we are using an extra array but it's size is fixed to 3
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color_freq_counter(3, 0);
        for (int num: nums) {
            ++color_freq_counter[num];
        }
        int i = 0, j;
        for (int color_freq_iter = 0; color_freq_iter < 3; ++color_freq_iter) {
            for (j = i; j < i + color_freq_counter[color_freq_iter]; ++j) {
                nums[j] = color_freq_iter;
            }
            i = j;
        }
    }
};
