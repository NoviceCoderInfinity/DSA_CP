class Solution {
public:
    string add_one (string s) {
        bool carry = true;
        int i = s.size() - 1;
        while (i >= 0 && carry) {
            if (s[i] == '0') {
                s[i] = '1';
                carry = false;
            } else {
                s[i] = '0';
                --i;
                carry = true;
            }
        }
        if (carry) {
            s.insert(s.begin(), '1');
        }
        return s;
    }

    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            }
            else {
                s = add_one(s);
            }
            ++steps;
        }
        return steps;
    }
};
