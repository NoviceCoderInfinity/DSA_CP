class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousands = {"", "M", "MM", "MMM"};
        vector<string> hundereds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> digits = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        int th = num / 1000; 
        int hu = (num - 1000 * th) / 100;
        int te = (num - 1000 * th - 100 * hu) / 10;
        int dig = num - 1000 * th - 100 * hu - 10 * te;

        string result = "";
        result += (thousands[th] + hundereds[hu] + tens[te] + digits[dig]);
        
        return result;
    }
};
