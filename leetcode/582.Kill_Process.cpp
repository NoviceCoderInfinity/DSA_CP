class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        map<int, vector<int>> mp; 
        vector<int> hit_list;
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            mp[ppid[i]].push_back(pid[i]);
        }

        q.push(kill);

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();

            hit_list.push_back(node);

            for (int child : mp[node]) {
                q.push(child);
            }
        }

        return hit_list;
    }
};
