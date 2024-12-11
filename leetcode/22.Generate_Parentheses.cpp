// Brute Force Solution
class Solution {
private:
    bool isValid(string test) {
        int left_count = 0;
        for (char c: test) {
            if (c == '(') {++left_count;}
            else {
                if (left_count == 0) {return false;}
                --left_count;
            }
        }
        return (left_count == 0);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<string> q;
        q.push("");
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() == 2*n) {
                if (isValid(curr)) {res.push_back(curr);}
                continue;
            }
            q.push(curr + "(");
            q.push(curr + ")");
        }
        return res;
    }
};

// BackTracking
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

//DP
class Solution {
private:
    map<int, vector<string>> dp = { {0, {""}}, {1, {"()"}} };
public:
    vector<string> generateParenthesis(int n) {
        if (dp.find(n) != dp.end()) {return dp[n];}
        for (int len = 2; len <= n; ++len) {
            vector<string> v;
            for (int i = 0; i < len; ++i) {
                for (const string& left: dp[i]) {
                    for (const string& right: dp[len - i -1]){
                        v.push_back( "(" + left + ")" + right) ;
                    }
                }
            }
            dp[len] = v;
        }
        return dp[n];
    }
};
