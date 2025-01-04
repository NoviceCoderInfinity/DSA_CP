class Solution {
public:
    int countDays(vector<int>& weights, int capacity) {
        int curr_weight = 0, days = 1;
        for (int weight: weights) {
            if (curr_weight + weight > capacity) {
                curr_weight = weight;
                ++days;
            }
            else {curr_weight += weight;}
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (countDays(weights, mid) <= days) {end = mid;}
            else {start = mid + 1;}
        }
        return start;
    }
};
