class Solution {
    unordered_map<string, vector<string>> mp;
public:
    void populate_dict(vector<string>& strs) {
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            unordered_map<char, int> mp_tmp;
            for(char ch: s) {++mp_tmp[ch];}
            s = "";
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                s += ch; s += to_string(mp_tmp[ch]);
            }
            if (mp.find(s) == mp.end()) {mp[s] = {strs[i]};}
            else {mp[s].push_back(strs[i]);}
        }
        return ;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        populate_dict(strs);
        for(auto iter: mp) {
            vector<string> res_i = iter.second;
            result.push_back(res_i);
        }
        return result;
    }
};
