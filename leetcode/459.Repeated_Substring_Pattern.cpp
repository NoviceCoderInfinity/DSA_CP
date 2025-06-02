// Solution 1: Repeated Matching
// Time Complexity: O(n sqrt(n)): The outer loop runs n times, the inner loop runs for number of factors of n which can't exceed sqrt(n)
// Space Complexity: O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string base_str = "";
        for (int i = 0; 2*i < s.size() - 1; ++i) {
            base_str += s[i];
            if (s.size() % base_str.size() != 0) {continue;}

            int j = 0; bool all_matches = true;
            for (j = 0; j < s.size(); j+=base_str.size()) {
                if (s.substr(j, base_str.size()) != base_str) {
                    all_matches = false;
                    break;
                }
            }
            if (all_matches) {return true;}
        }
        return false;
    }
};

// Solution 2: String Concatenation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string concatenatd_s = s + s;
        if (concatenatd_s.substr(1, concatenatd_s.size() - 2).find(s) != -1) return true;
        return false;
    }
};
