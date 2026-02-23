class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if ((s.size() - k + 1 < (1 << k) || (s.size() < k))) {
            return false;
        }
        set<string> st;
        
        string tmp = s.substr(0, k);
        st.insert(tmp);
        
        for (int i = 1; i <= s.size() - k; ++i) {
            tmp = tmp.substr(1) + s[i + k -1];
            st.insert(tmp);
        }
        if (st.size() == (1 << k)) {
            return true;
        }
        return false;

    }
};
