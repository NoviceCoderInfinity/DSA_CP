// One Hashmap
// Time Complexity: O(n+m)
// Space Complexity: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (char c: ransomNote) {
            mp[c]++;
        }

        for (char c: magazine) {
            if (mp.find(c) != mp.end()) mp[c]--;
            else {
                continue;
            }
        }

        for (const auto& pair: mp) {
            if (pair.second > 0) return false;
        }

        return true;
    }
};

// One Hashmap Optimised
// Time Complexity: O(n+m)
// Space Complexity: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (char c: magazine) {
            mp[c]++;
        }

        for (char c: ransomNote) {
            if (mp[c] == 0) return false;
            --mp[c];
        }

        return true;
    }
};


