class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() == 1) {return s;}
        vector<string> arr(numRows, "");
        int last_row = 0; bool dir_down = false;
        for (int i = 0; i < s.size(); ++i) {
            if (last_row == 0 || last_row == numRows - 1) {dir_down = !dir_down;}
            arr[last_row].push_back(s[i]);
            if (dir_down) {++last_row;} 
            else {--last_row;}
        }
        string result = "";
        for (int i = 0; i < arr.size(); ++i) {
            result += arr[i];
        }
        return result;
    }
};
