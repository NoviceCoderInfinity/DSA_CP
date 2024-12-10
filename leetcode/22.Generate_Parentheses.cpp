class Solution {
private:
    vector<string> v;
public:
    void backtrack(int n, int open, int close, string curr) {
        if (open < close) {return ;}
        if (open == n && close == n) {v.push_back(curr); return;}
        if (open == close || open < n) {backtrack(n, open + 1, close, curr + "(");}
        backtrack(n, open, close + 1, curr + ")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, "");
        return v;
    }
};
