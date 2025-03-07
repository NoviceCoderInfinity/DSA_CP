class Solution {
public:
    string multiply_string_with_char(string num, char c, int pos_shift = 0) {
        string result = ""; int carry = 0; int i;
        for (int i = 0; i < pos_shift; ++i) {
            result += '0';
        }
        for (i = num.size() - 1; i >= 0; --i) {
            int t = (num[i] - '0') * (c - '0') + carry;
            carry = t / 10;
            t %= 10;
            result = (char)(t + '0') + result;
        }
        if (carry) {
            result = (char)(carry + '0') + result;
        }
        return result;
    }

    string add_strings(string s1, string s2) {
        string result = "";
        int s1_size = s1.size(), s2_size = s2.size();
        int m_size = min(s1_size, s2_size), carry = 0;
        int i, j;
        for (i = s1_size - 1, j = s2_size - 1; i >= 0 && j >= 0; --i, --j) {
            int t = (s1[i] - '0') + (s2[j] - '0') + carry;
            carry = t / 10; t %= 10;
            result = (char)(t + '0') + result;
        }
        while (i >= 0) {
            int t = (s1[i--] - '0') + carry;
            carry = t / 10;
            t %= 10;
            result = (char)(t + '0') + result;
        }
        while (j >= 0) {
            int t = (s2[j--] - '0') + carry;
            carry = t / 10;
            t %= 10;
            result = (char)(t + '0') + result;
        }
        if (carry) {
            result = (char) (carry + '0') + result;
        }
        return result;
    }

    string multiply(string num1, string num2) {
        if (num2 == "0" || num1 == "0") {return "0";}
        else if (num2 == "1") {return num1;}
        else if (num1 == "1") {return num2;}
        if (num1.size() < num2.size()) {return multiply(num2, num1);}
        string result = "0"; int pos_shift = num2.size() - 1;
        for (char c: num2) {
            string result_temp = multiply_string_with_char(num1, c, pos_shift);
            result = add_strings(result, result_temp);
            --pos_shift;
        }
        return result;
    }
};
