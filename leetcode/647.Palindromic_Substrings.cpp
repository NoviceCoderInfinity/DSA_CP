// Brute Force Solution: Check whether every string is a Palindrome or not
// Time complexity: O(N^3): O(N^2) for possible strings, and O(N) for each check
// Space Complexity: O(1)
class Solution {
    bool is_palindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left; --right;
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for (int left = 0; left < s.size(); ++left) {
            for (int right = left; right < s.size(); ++right) {
                count += is_palindrome(s, left, right);
            }
        }
        return count;
    }
};

// 2D Dynamic Programming
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};

// Expand around a Palindrome
// Time Complexity: O(N^2)
// Space Complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += count_around_the_center(s, i, i);
            count += count_around_the_center(s, i, i+1);
        }
        return count;
    }

    int count_around_the_center(string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {break;}
            --left; ++right; ++count;
        }

        return count;
    }
};
