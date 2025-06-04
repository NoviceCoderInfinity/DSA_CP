// Solution 1
// Time Complexity: O(m * n log (n))
// Space Complexity: O(log n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int p_sz = p.size(), s_sz = s.size();
        sort(p.begin(), p.end());
        for (int i = 0; i <= s_sz - p_sz; ++i) {
            string tmp = s.substr(i, p_sz); sort(tmp.begin(), tmp.end());
            if (tmp == p) {result.push_back(i);}
        }
        return result;
    }
};
