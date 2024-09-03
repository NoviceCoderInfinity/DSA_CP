class Solution {
public:
    string transform_str_to_int(string s) {
        string result = "";
        for (char ch: s) {
            result += to_string( static_cast<int>(ch - 'a' + 1) );
        }
        return result;
    }

    int getLucky(string s, int k) {
        string num_fy = transform_str_to_int(s); int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (char ch: num_fy) {sum += static_cast<int>(ch - '0');}
            num_fy = to_string(sum);
        }
        return sum;
    }
};
