class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> remainderCount;        
        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            ++remainderCount[rem];
        }
        if (remainderCount[0] % 2 != 0) {return false;}
        for (int i = 1; i <= k / 2; ++i) {
            if (i != k - i) {
                if (remainderCount[i] != remainderCount[k - i]) {return false;}
            } else {
                if (remainderCount[i] % 2 != 0) {return false;}
            }
        }
        return true;
    }
};
