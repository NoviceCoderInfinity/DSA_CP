class Solution {
public:
    string largestOddNumber(string num) {
        int index = num.size() - 1;
        while (index > 0) {
            if ((num[index] - '0') % 2 == 1) {break;}
            --index;
        }
        if ((num[index] - '0') % 2 == 0) {return "";}
        return num.substr(0, index+1);
    }
};
