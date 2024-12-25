// Iterative Solution
class Solution {
public:
    bool sanityCheck(int result, int dig) {
        return (result > (INT_MAX - dig) / 10) || (result < (INT_MIN + dig) / 10);
    }
    int myAtoi(string s) {
        int i = 0, result = 0; bool positive = true;
        
        while(i < s.size() && s[i] == ' ') {++i;} // WhiteSpace

        if (s[i] == '-') {positive = false; ++i;} // Sign Check
        else if (s[i] == '+') {++i;}
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (sanityCheck(result, digit)){
                return positive ? INT_MAX : INT_MIN;
            }
            result *= 10; result += digit;
            ++i;
        }
        return positive ? result : -result;
    }
};
