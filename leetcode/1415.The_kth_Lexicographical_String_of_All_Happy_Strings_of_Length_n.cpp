class Solution {
public:
    void backtrack(int n, int &k, string &curr, string &ans) {
        if (curr.size() == n) {
            k--;
            if (k == 0) ans = curr;
            return;
        }

        for (char c : {'a','b','c'}) {
            if (!curr.empty() && curr.back() == c) continue;

            curr.push_back(c);
            backtrack(n, k, curr, ans);
            curr.pop_back();

            if (!ans.empty()) return;
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string ans = "";
        backtrack(n, k, curr, ans);
        return ans;
    }
};
