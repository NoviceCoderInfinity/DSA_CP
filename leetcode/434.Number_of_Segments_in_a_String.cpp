class Solution {
public:
    int countSegments(string s) {
        int segments = 0, iter = 0;
        while (iter < s.size()) {
            if (s[iter] != ' ') {
                ++segments;
                while(iter < s.size() && s[iter] != ' ') {++iter;}
            }
            else {++iter;}
        }
        return segments;
    }
};
