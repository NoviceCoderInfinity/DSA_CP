// Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)
// Result: TLE
class Solution {
public:
    bool check_palindrome(string s, int i, int j, int k) {
        return (s[i] == s[k]);
    }
    int countPalindromicSubsequence(string s) {
        set<string> palindromes;
        for (int i = 0; i < s.size() - 2; ++i) {
            for (int j = i + 1; j < s.size() - 1; ++j) {
                for (int k = j + 1; k < s.size(); ++k) {
                    if (check_palindrome(s, i, j, k)) {
                        string palindrome = "";
                        palindrome += s[i];
                        palindrome += s[j];
                        palindrome += s[k];
                        palindromes.insert(palindrome);
                    }
                }
            }
        }
        return palindromes.size();
    }
};

// Look Up + Brute Force
// Time Complexity: O(n^3) slightly better than pure brute force
// Space Complexity: O(n)
// Result: TLE
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        set<string> unique_palindromes;
        map<char, vector<int>> mp;

        for (int i = 0; i < n; ++i) {
            mp[ s[i] ].push_back(i);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (i * 2 > n) {
                for (int j = i + 1; j < n; ++j) {
                    vector<int> iter_sj = mp[ s[j] ];
                    for (int v: iter_sj) {
                        if (v < i) {
                            string palindrome = "";
                            palindrome += s[v];
                            palindrome += s[i];
                            palindrome += s[j];
                            unique_palindromes.insert(palindrome);
                        }
                    }
                }
            } else {
                for (int j = 0; j < i; ++j) {
                    vector<int> iter_sj = mp[ s[j] ];
                    for (int v: iter_sj) {
                        if (v > i) {
                            string palindrome = "";
                            palindrome += s[j];
                            palindrome += s[i];
                            palindrome += s[v];
                            unique_palindromes.insert(palindrome);
                        }
                    }
                }
            }
        }
        return unique_palindromes.size();
    }
};


// Count Letters in between
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        set<string> unique_palindromes;
        map<char, vector<int>> mp;

        for (int i = 0; i < n; ++i) {
            mp[ s[i] ].push_back(i);
        }

        for (auto& pair: mp) {
            char c = pair.first;
            vector<int> pos = pair.second;

            if (pos.size() >= 2) {
                int first_occurrence = pos[0];
                int last_occurrence = pos[pos.size() - 1];
                
                if (last_occurrence - first_occurrence >= 2) {
                    for (int i = first_occurrence + 1; i < last_occurrence; i++) {
                        string palindrome = "";
                        palindrome += c;
                        palindrome += s[i];
                        palindrome += c;
                        unique_palindromes.insert(palindrome);
                    }
                }
            }

        }
        return unique_palindromes.size();
    }
};

// Pre-Computation First and Last Indices
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); ++i) {
            int curr = s[i] - 'a';
            if (first[curr] == -1) first[curr] = i;
            last[curr] = i;
        }

        int unique_palindrome_count = 0;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            unordered_set<char> in_between;
            for (int j = first[i] + 1; j < last[i]; ++j) {
                in_between.insert(s[j]);
            }

            unique_palindrome_count += in_between.size();
        }

        return unique_palindrome_count;
    }
};
