class Solution {
public:
    int bouquets_count(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquet = 0; bool possible_bouquet = true;
        for(int i = 0; i <= bloomDay.size() - k; ) {
            if (bloomDay[i] <= mid) {
                possible_bouquet = true;
                int iter = 0;
                for ( ; iter < k; ++iter) {
                    if (bloomDay[i+iter] <= mid) {continue;}
                    else {possible_bouquet = false; break;}
                }
                i+=iter;
                if (possible_bouquet) {++bouquet;}
                if (bouquet > m) {bouquet = INT_MAX; break;}
            }
            else {++i;}
        }
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        while(start < end) {
            int mid = start + (end - start) / 2;
            if (bouquets_count(bloomDay, m, k, mid) >= m) {end = mid;}
            else {start = mid + 1;}
        }
        if (bouquets_count(bloomDay, m, k, start) >= m) {return start;}
        else {return -1;}
    }
};
