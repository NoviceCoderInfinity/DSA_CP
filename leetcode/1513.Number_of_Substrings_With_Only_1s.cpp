class Solution {
public:
    static constexpr int MODULO = int(1E9) + 7;

    int numSub(string s) {
        int i = 0; 
        long long int count = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                ++i; continue;
            }
            int consecutive_one_count = 0;
            while ((i < s.size()) && (s[i] == '1')) {
                ++i; ++consecutive_one_count;
            }
            count = count + (1LL + (long long)consecutive_one_count) * consecutive_one_count / 2;
            count = count % MODULO;
        }
        return count;
    }
};
