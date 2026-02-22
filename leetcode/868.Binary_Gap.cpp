# Solution 1: Brute Force / Calculation
class Solution {
public:
    string get_string_binary_number(int number) {
        if (number == 0) return "0";
        string result = "";
        while (number > 0) {
            result += char('0' + (number%2));
            number /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int binaryGap(int n) {
        int max_dist = 0;
        int last_index = -1;
        int index = 0;
        
        string binary_number = get_string_binary_number(n);
        for(char c: binary_number) {
            if (c == '1') {
                cout << index << endl;
                if (last_index != -1) {
                    max_dist = max(max_dist, index - last_index);
                }
                last_index = index;
            }
            ++index;
        }
        return max_dist;
    }
};

# Solution 2: One Pass
class Solution {
public:
    int binaryGap(int n) {
        int search_index = floor(log2(n)) + 1;
        int N = n;
        int last = -1, max_dist = 0;
        for (int i = 0; i < search_index; ++i) {
            if ((N & 1) > 0) {
                if (last != -1) {
                    max_dist = max(max_dist, i - last);
                }
                last = i;
            }
            N = N / 2;
        }
        return max_dist;
    }
};
