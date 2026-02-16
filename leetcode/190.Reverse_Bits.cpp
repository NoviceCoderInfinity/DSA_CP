class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i = 0;
        while(i < 32) {
            ++i;
            bool digit = n & 1;
            n = n >> 1;
            result = result << 1;
            result = result | digit;
        }
        return result;
    }
};
