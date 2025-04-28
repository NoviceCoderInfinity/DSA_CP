// Extract the digit and add it to the result while preserving a and b
// Time Complexity: O(1) iterates over both the elements 32 times
// Space Complexity: O(1) uses only one variable and keeps adding to it
// Result: Accepted
class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int place = 0;  // Start from bit position 0
        int digit_extractor = 1;
        bool carry = false;

        while (place < 32) {
            bool a_dig = a & digit_extractor;
            bool b_dig = b & digit_extractor;

            bool sum_bit = a_dig ^ b_dig ^ carry;

            if (sum_bit) {
                result |= digit_extractor;
            }
            carry = (a_dig & b_dig) | (a_dig & carry) | (b_dig & carry);
            ++place;
            digit_extractor <<= 1;
        }

        return result;
    }
};

