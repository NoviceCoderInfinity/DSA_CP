class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int right_index = digits.size() - 1;
        int carry = 1;

        while(carry != 0 && right_index >= 0) {
            int sum = digits[right_index] + carry;
            carry = sum / 10;
            digits[right_index] = sum % 10;
            --right_index;
        }
        if (carry) {
            digits.insert(digits.begin() + 0, carry);
        }
        
        return digits;
    }
};
