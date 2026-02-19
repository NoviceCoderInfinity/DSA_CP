# Solution 1, TLE
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = count(s.begin(), s.end(), '0');
        int max_iter = min(ones, zeros);

        int total = 0;
        string ones_str = "";
        string zeros_str = "";

        for (int i = 1; i <= max_iter; ++i) {
            ones_str += "1";
            zeros_str += "0";

            string pattern1 = ones_str + zeros_str;
            string pattern2 = zeros_str + ones_str;

            size_t pos = s.find(pattern1);
            while (pos != string::npos) {
                total++;
                pos = s.find(pattern1, pos + 1);
            }

            pos = s.find(pattern2);
            while (pos != string::npos) {
                total++;
                pos = s.find(pattern2, pos + 1);
            }
        }

        return total;
    }
};


# Solution 2, Optimised solution
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev_cnt = 0, curr_cnt = 1;
        int total = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++curr_cnt;
            } else {
                total += min(prev_cnt, curr_cnt);
                prev_cnt = curr_cnt;
                curr_cnt = 1;
            }
        }

        total += min(prev_cnt, curr_cnt);
        return total;
    }
};

