// Recursion (Plain)
// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {return n;}
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Top-Down Recursion with Memoization
// Time Complexity: O(n)
// Space Complexity: O(n) (Recursion Stack + Map)
class Solution {
public:
    map<int, int> dp;
    Solution() {dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;}

    int climbStairs(int n) {
        if (dp.find(n) == dp.end()) {
            dp[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return dp[n];
    }
};

// Bottom-Up Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    map<int, int> dp;
    Solution() {dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;}

    int climbStairs(int n) {
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        for (int i = 4; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
