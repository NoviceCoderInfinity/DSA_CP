class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for (int len_N = 1; len_N <= k; ++len_N) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return len_N;
        }
        return -1;
    }
};
