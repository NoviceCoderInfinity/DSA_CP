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
