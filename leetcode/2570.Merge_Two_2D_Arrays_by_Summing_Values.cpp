// Two Pointer Solution
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> mergedArray;
        int iter1 = 0, iter2 = 0;
        while (iter1 < n1 && iter2 < n2) {
            if (nums1[iter1][0] < nums2[iter2][0]) {
                mergedArray.push_back({nums1[iter1][0], nums1[iter1][1]});
                ++iter1;
            }
            else if (nums1[iter1][0] == nums2[iter2][0]) {
                mergedArray.push_back({nums1[iter1][0], nums1[iter1][1] + nums2[iter2][1]});
                ++iter1; ++iter2;
            }
            else {
                mergedArray.push_back({nums2[iter2][0], nums2[iter2][1]});
                ++iter2;
            }
        }
        while (iter1 < n1) {
            mergedArray.push_back({nums1[iter1][0], nums1[iter1][1]}); ++iter1;
        }
        while (iter2 < n2) {
            mergedArray.push_back({nums2[iter2][0], nums2[iter2][1]}); ++iter2;
        }
        return mergedArray;
    }
};
