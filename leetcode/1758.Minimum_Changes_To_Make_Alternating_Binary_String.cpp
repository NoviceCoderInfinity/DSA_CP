class Solution {
public:
    int minOperations(string s) {
        int del_01 = 0;
        int del_10 = 0;

        bool odd_index = false;
        for (char c: s) {
            if (odd_index) {
                del_01 += !(c == '1');
                del_10 += !(c == '0');
            } else {
                del_01 += (c == '1');
                del_10 += (c == '0');
            }

            odd_index = !odd_index;
        }

        return min(del_01, del_10);
    }
};
