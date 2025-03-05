// Solution 1
class Solution {
public:
    long long coloredCells(int n) {
        long long result = 0;
        long long n_long = static_cast<long long> (n);
        result += n_long * n_long;
        result += (n_long - 1) * (n_long - 1);
        return result;
    }
};
