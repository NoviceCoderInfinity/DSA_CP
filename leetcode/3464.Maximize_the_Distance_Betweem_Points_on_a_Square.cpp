class Solution {
public:
    bool is_possible(long long val, vector<long long>& arr, int k, long long perimeter) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            long long start = arr[i];
            long long end = start + perimeter - val;
            long long last = start;
            int count = 1;

            for (int j = 1; j < k; j++) {
                auto it = lower_bound(arr.begin(), arr.end(), last + val);
                if (it == arr.end() || *it > end) {
                    count = 0;
                    break;
                }
                last = *it;
                count++;
            }

            if (count >= k) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;
        long long perimeter = 4LL * side;

        for (auto& point: points) {
            long long x = point[0], y = point[1];
            if (x == 0)         arr.push_back(y);
            else if (y == side) arr.push_back(x + side);
            else if (x == side) arr.push_back(3LL * side - y);
            else                arr.push_back(4LL * side - x);
        }

        sort(arr.begin(), arr.end());

        long long low = 1, high = perimeter, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (is_possible(mid, arr, k, perimeter)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
