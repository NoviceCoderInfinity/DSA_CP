class Solution {
    private List<String> v = new ArrayList<>();

    private void backtrack(int n, int open, int close, String curr) {
        if (open < close) {return ;}
        if (open == n && close == n) {v.add(curr); return;}
        if (open == close || open < n) {backtrack(n, open + 1, close, curr + "(");}
        backtrack(n, open, close + 1, curr + ")");
        return ;
    }

    public List<String> generateParenthesis(int n) {
        backtrack(n, 0, 0, "");
        return v;
    }
}
