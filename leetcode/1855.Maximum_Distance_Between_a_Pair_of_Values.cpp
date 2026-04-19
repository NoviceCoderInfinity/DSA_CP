// Approach 1: Two pointers
// Time Complexity: O(m + n)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        int max_dist = 0;

        while (idx1 < n1 && idx2 < n2) {
            if (nums1[idx1] > nums2[idx2]) ++idx1;
            else {
                max_dist = max(max_dist, idx2 - idx1);
                ++idx2;
            }
        }

        return max_dist;
    }
};

// Approach 2: Binary Search
// Time Complexity: O(m log n)
// Space Complexity: O(1)
class Solution {
public:
    int binary_search(vector<int>& nums1, int right, int val2) {
        int left = 0, ans = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums1[mid] <= val2) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        if (ans >= nums1.size()) return 0;
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int idx1 = n1 -1, idx2 = n2 - 1;
        int max_dist = 0;

        while (idx1 >= 0 && idx2 >= 0) {
            idx1 = min(idx1, idx2);
            idx1 = binary_search(nums1, idx1, nums2[idx2]);
            if (nums1[idx1] <= nums2[idx2] && idx1 <= idx2)
                max_dist = max(max_dist, idx2 - idx1);
            --idx2;
        }

        return max_dist;
    }
};
