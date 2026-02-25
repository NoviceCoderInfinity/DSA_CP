class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b){
            int a_bits = __builtin_popcount(a), b_bits = __builtin_popcount(b);
            if (a_bits == b_bits) {
                return a < b;
            } else {
                return a_bits < b_bits;
            }
        });
        return arr;
    }
};
