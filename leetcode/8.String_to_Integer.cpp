// Recursive Solution
class Solution {
    int result = 0;
    bool positive = true;
public:
    bool sanityCheck(int result, int dig) {
        return (result > (INT_MAX - dig) / 10) || (result < (INT_MIN + dig) / 10);
    }

    void customAtoi(string s) {        
        if (s.size() == 0 || !(s[0] >= '0' && s[0] <= '9')) {return ;}
        int digit = s[0] - '0';
            if (sanityCheck(result, digit)){
                if (positive) {result = INT_MAX;}
                else {result = INT_MIN; positive = true;}
                return;
            }
        result *= 10; result += digit;
        customAtoi(s.substr(1));
    }

    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') {++i;}
        if (s[i] == '-') {positive = false; ++i;}
        else if (s[i] == '+') {++i;}
        customAtoi(s.substr(i));
        return positive ? result : -result;
    }
};
