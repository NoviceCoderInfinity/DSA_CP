class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if (skill.size() % 2 != 0) {return -1;}
        sort(skill.begin(), skill.end());
        long long total_chemistry = 0;
        int team_skill = skill.front() + skill.back();
        int left = 0, right = skill.size() - 1;
        while (left < right) {
            if (skill[left] + skill[right] != team_skill) {return -1;}
            total_chemistry += (long long)(skill[left++]) * (long long)(skill[right--]);
        }
        return total_chemistry;
    }
};
