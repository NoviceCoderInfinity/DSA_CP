class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        vector<int> evenIndex(26, 0), oddIndex(26, 0);
        int iter = 0, n = s1.size();
        while (iter < n) {
            evenIndex[s1[iter] - 'a']++;
            if (iter >= n-1) break;
            oddIndex[s1[++iter] - 'a']++;
            ++iter;
        }

        iter = 0;
        while (iter < n) {
            evenIndex[s2[iter] - 'a']--;
            bool a = (evenIndex[s2[iter] - 'a'] < 0);
            bool b = false;
            if (iter < n-1) {
                oddIndex[s2[iter+1] - 'a']--;
                b = (oddIndex[s2[iter+1] - 'a'] < 0);
            }
            if (a || b) return false;
            iter += 2;
        }

        return true;
    }
};
