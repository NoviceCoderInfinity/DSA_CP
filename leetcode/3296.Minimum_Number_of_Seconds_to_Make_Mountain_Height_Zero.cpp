// Approach 1: Binary Search + Validation
// Time Complexity: O(n * log( max_worker_time * mountainHeight^2 ) )
// Space Complexity: O(1)
class Solution {
public:
    bool check_valid_mountain_height(int mountainHeight, vector<int>& workerTimes, long long given_time) {
        for (long long worker: workerTimes) {
            // to obtaint the height affected by the worker in the given time
            // height_affected ^ 2 + height_affected - (2 * given_time / worker_time) = 0
            // a x^2 + b x + c = 0
            long long c = 2 * given_time / worker;
            long long height_affected = -1 + sqrt(1 + 4 * c);
            height_affected /= 2;
            mountainHeight -= height_affected;
            if (mountainHeight <= 0) {
                return true;
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int max_ele = *max_element(workerTimes.begin(), workerTimes.end());
        long long low = 1;
        long long high = (static_cast<long long>(max_ele) * mountainHeight * (mountainHeight + 1)) / 2;

        while (low < high) {
            long long mid = (high - low) / 2 + low;
            if (check_valid_mountain_height(mountainHeight, workerTimes, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
