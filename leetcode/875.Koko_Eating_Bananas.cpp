class Solution {
public:
    int hoursEating(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile: piles) {
            hours += (pile / k);
            if (pile % k != 0) {++hours;}
            if (hours > h) {return h+1;}
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        if (h < piles.size()) {return -1;}

        int start = 1, end = *max_element(piles.begin(), piles.end());

        while(start < end) {
            int mid = (end - start) / 2 + start;
            if (hoursEating(piles, mid, h) <= h) {end = mid;} // koko can eat, reduce the speed
            else {start = mid + 1;} // koko can't eat, increase the speed
        }

        return start;
    }
};
