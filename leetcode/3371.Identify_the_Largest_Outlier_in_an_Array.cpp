class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long int sum = 0;
        map<int, int> umap;
        for (int num: nums) {
            sum += static_cast<long int>(num);
            if (umap.find(num) == umap.end()) {umap[num] = 1;}
            else {umap[num] += 1;}
        }
        int largest_outlier = INT_MIN;
        for (int num: nums) {
            long int temp = sum - num;
            if ((temp % 2 != 0) || (umap.find(temp/2) == umap.end())) {continue;}
            if (num == temp/2 && umap[num] == 1) {continue;}
            if (num > largest_outlier) {largest_outlier = num;}
        }
        return largest_outlier;
    }
};
