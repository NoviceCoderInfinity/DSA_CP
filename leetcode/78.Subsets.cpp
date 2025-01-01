// Solution 1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back({});
        for (int num: nums) {
            int n = answer.size();
            for (int i = 0; i < n; ++i) {
                vector<int> tmp = answer[i];
                tmp.push_back(num);
                answer.push_back(tmp);
            }
        }
        return answer;
    }
};

// Solution 2
class Solution {
public:
    void next_iter(string& iter) {
        int carry = 1;
        for(int i = iter.size() - 1; i >= 0; --i) {
            if (carry == 0) {break;}
            if (iter[i] == '0' && carry) {iter[i] = '1'; carry = 0;}
            else if (iter[i] == '1' && carry) {iter[i] = '0'; carry = 1;}}
            return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        string iter(nums.size(), '0');
        for(int i = 0; i < (int)(pow(2, nums.size())); ++i) {
            vector<int> temp;
            for(int j = 0; j < iter.size(); ++j) {
                if (iter[j] == '1') {temp.push_back(nums[j]);}}
            answer.push_back(temp); next_iter(iter);}
        return answer;
    }
};
