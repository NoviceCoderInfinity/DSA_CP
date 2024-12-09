class Solution {
    public int getLargestOutlier(int[] nums) {
        long sum = 0;
        HashMap<Integer, Integer> umap = new HashMap<>();
        for (int num: nums) {
            sum += num;
            umap.put(num, umap.getOrDefault(num, 0) + 1);
        }
        int largest_outlier = Integer.MIN_VALUE;
        for (int num: nums) {
            long temp = sum - num;
            if ((temp % 2 != 0) || (!umap.containsKey((int)temp/2))) {continue;}
            if (num == temp/2 && umap.get(num) == 1) {continue;}
            if (num > largest_outlier) {largest_outlier = num;}
        }
        return largest_outlier;
    }
};
