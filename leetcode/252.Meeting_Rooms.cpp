// Solution
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {return true;}
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 0;
        for (vector<int> interval: intervals) {
            if ((interval[0] >= right) || (interval[1] <= left)) {
                right = max(right, interval[1]);
                left = min(left, interval[0]);
            }
            else {return false;}
        }
        return true;
    }
};
