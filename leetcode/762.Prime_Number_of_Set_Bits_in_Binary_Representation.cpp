class Solution {
public:
    set<int> prime_numbers = {2, 3, 5, 7, 11, 13, 17, 19};
    bool count_set_bits(int num) {
        int set_bits = 0;
        while (num) {
            set_bits += num & 1;
            num = num >> 1;
        }
        if (prime_numbers.find(set_bits) != prime_numbers.end()) {
            return true;
        }
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            count += count_set_bits(i);
        }
        return count;
    }
};
