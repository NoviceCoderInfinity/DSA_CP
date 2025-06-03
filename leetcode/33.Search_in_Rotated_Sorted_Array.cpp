// Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
private:
    int get_pivot(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[right]) {left = mid + 1;}
            else {right = mid;}
        }
        return left;
    }
public:
    int binary_search(vector<int>& nums, int left, int right, int target) {
        if (right < left) {right = left;}
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {return -1;}

        int pivot = get_pivot(nums);
        int n = nums.size();

        if (nums[pivot] <= target && target <= nums.back()) {return binary_search(nums, pivot, n-1, target);}
        else {return binary_search(nums, 0, pivot-1, target);}
    }
};
