class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int del_01 = 0, del_10 = 0;
        bool odd_parity = false;

        for (int i = 0; i < n; i++) {
            if (odd_parity) {
                del_01 += (s[i] != '1');
                del_10 += (s[i] != '0');
            } else {
                del_01 += (s[i] != '0');
                del_10 += (s[i] != '1');
            }
            odd_parity = !odd_parity;
        }

        int result = min(del_01, del_10);
        odd_parity = false;
        for (int i = 0; i < n - 1; i++) {
            char c = s[i];

            if (odd_parity) {
                del_01 -= (c != '1');
                del_10 -= (c != '0');
            } else {
                del_01 -= (c == '1');
                del_10 -= (c == '0');
            }
            odd_parity = !odd_parity;

            int new_pos = n + i;

            if (c != (new_pos % 2 ? '1' : '0')) del_01++;
            if (c != (new_pos % 2 ? '0' : '1')) del_10++;

            result = min(result, min(del_01, del_10));
        }

        return result;
    }
};
