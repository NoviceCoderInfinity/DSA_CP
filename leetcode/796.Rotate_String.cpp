// Iterative Solution
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {return false;}
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s.substr(i) + s.substr(0, i) == goal) {return true;}
        }
        return false;
    }
};

// Concatenation Solution
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {return false;}
        string doubled = s + s;
        return doubled.find(goal) < doubled.length();
    }
};
