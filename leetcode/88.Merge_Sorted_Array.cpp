// Solution 1: 3 Pointers (from the End)
// Time Complexity: O(m+n)
// Space Complexity: O(1)
#include <bits/stdc++.h> 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter_nums1 = m - 1, iter_nums2 = n - 1;
        for (int p = nums1.size() - 1; p >= 0; --p) {
            if (iter_nums2 < 0) {break;}
            if (iter_nums1 >= 0 && nums1[iter_nums1] > nums2[iter_nums2]) {
                nums1[p] = nums1[iter_nums1--];
            }
            else {
                nums1[p] = nums2[iter_nums2--];
            }
        }
    }
};

// Solution 2: Merge and Sort
// Time Complexity: O((m + n) log(m + n))
// Space Complexity: O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m, j = 0; 
        while (i < nums1.size() && j < nums2.size()) {
            nums1[i] = nums2[j]; ++i; ++j;  }
        sort(nums1.begin(), nums1.end());
    }
};
