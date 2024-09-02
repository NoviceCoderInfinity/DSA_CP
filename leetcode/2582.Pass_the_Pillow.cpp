class Solution {
public:
    int passThePillow(int n, int time) {
        int curr_pos = 1;
        int curr_time = 0;
        int direction = 1;
        while (curr_time < time) {
            if (0 < curr_pos  + direction && curr_pos + direction <= n) {
                curr_pos += direction; ++curr_time;}
            else {direction *= -1;}
        }
        return curr_pos;
    }
};
