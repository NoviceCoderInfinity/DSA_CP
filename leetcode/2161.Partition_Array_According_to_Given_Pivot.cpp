// Solution 1
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        int same_as_pivot_count = 0;
        vector<int> greater_than_arr;
        for (int num: nums) {
            if (num < pivot) {result.push_back(num);}
            else if (num == pivot) {++same_as_pivot_count;}
            else {greater_than_arr.push_back(num);}
        }
        while (same_as_pivot_count--) {
            result.push_back(pivot);
        }
        result.insert(result.end(), greater_than_arr.begin(), greater_than_arr.end());
        return result;
    }
};
