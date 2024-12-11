// Brute-Force
class Solution {
    private boolean isValid(String test) {
        int left_count = 0;
        for (char c: test.toCharArray()) {
            if (c == '(') {++left_count;}
            else {
                if (left_count == 0) {return false;}
                --left_count;
            }
        }
        return (left_count == 0);
    }

    public List<String> generateParenthesis(int n) {
        List<String> v = new ArrayList<>();
        Queue<String> q = new LinkedList<>(Arrays.asList(""));

        while (!q.isEmpty()) {
            String curr = q.poll();

            if (curr.length() == 2*n) {
                if (isValid(curr)) {v.add(curr);}
                continue;
            }
            q.offer(curr + "(");
            q.offer(curr + ")");
        }
        return v;
    }
}

// BackTracking
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

//DP
class Solution {
    private HashMap<Integer, List<String>> dp = new HashMap<>();
    public List<String> generateParenthesis(int n) {
        dp.put(0, Arrays.asList(""));
        if (dp.containsKey(n)) {return dp.get(n);}
        for (int len = 1; len <= n; ++len) {
            List<String> v = new ArrayList<>();
            for (int i = 0; i < len; ++i) {
                for (String left: dp.get(i)) {
                    for (String right: dp.get(len - i - 1)) {
                        v.add("(" + left + ")" + right);
                    }
                }
            }
            dp.put(len, v);
        }
        return dp.get(n);
    }
}
