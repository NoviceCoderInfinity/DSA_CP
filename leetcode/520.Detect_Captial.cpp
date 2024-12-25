class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0 || word.size() == 1) {return true;}

        bool match = true;
        for (int i = 1; i < word.size(); ++i) {
            if (('A' <= word[i] && word[i] <= 'Z' && 'A' <= word[0] && word[0] <= 'Z') ||
                ('a' <= word[i] && word[i] <= 'z' && 'a' <= word[0] && word[0] <= 'z')) {
                continue;
            }
            else {match = false; break;}
        }

        if (match) {return true;}

        match = true;
        for (int i = 1; i < word.size(); ++i) {
            if ('a' <= word[i] && word[i] <= 'z' && 'A' <= word[0] && word[0] <= 'Z') {
                continue;
            }
            else {match = false; break;}
        }

        return match;
    }
};
