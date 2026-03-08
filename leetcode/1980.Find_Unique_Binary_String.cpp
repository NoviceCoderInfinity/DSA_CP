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
