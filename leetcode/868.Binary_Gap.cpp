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
