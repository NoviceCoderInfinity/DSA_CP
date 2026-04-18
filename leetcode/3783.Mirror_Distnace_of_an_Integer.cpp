class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int n_cpy = n;
        while (n_cpy) {
            int digit = n_cpy % 10;
            n_cpy = n_cpy / 10;
            rev = rev * 10;
            rev += digit;
        }
        return abs(rev - n);
    }
};
