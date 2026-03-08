// Recursive string search
// Time Complexity: O( (2^n) * (n log n) )
// Space Complexity: O(n)
class Solution {
public:
    void add_one(string& s) {
        bool carry = true;
        int i = s.size();
        while(carry) {
            --i;
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
                carry = false;
            }
        }
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(), nums.end());
        string s(nums.size(), '0');
        while(st.find(s) != st.end()) {
            add_one(s);
        }
        return s;
    }
};

// Cantor's Diagonalization
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res(n, '0');

        for (int i = 0; i < n; ++i) {
            if (nums[i][i] == '0') {
                res[i] = '1';
            }
            else {
                res[i] = '0';
            }
        }

        return res;
    }
};
