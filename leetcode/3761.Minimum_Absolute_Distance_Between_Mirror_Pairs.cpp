class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x) {
            int digit = x % 10;
            x = x / 10;

            num = num * 10;
            num = num + digit;
        }
        return num;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> prev;
        int n = nums.size();
        int res = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) 
                res = min(res, i - prev[x]);
            prev[reverse(x)] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};
