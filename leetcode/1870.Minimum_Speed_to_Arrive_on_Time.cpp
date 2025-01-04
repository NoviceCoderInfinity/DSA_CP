class Solution {
public:
    double timeRequired(vector<int>& dist, int speed) {
        double time = 0.0;
        for (int i = 0 ; i < dist.size() - 1; i++) {
            time += ceil(static_cast<double>(dist[i]) / static_cast<double>(speed));
        }
        time += static_cast<double>(dist.back()) / static_cast<double>(speed);
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1, end = 1e7;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (timeRequired(dist, mid) <= hour) {end = mid - 1;}
            else {start = mid + 1;}
        }
        return (start > 1e7) ? -1 : start;
    }
};

