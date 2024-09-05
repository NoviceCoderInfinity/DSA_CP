class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        if (n == 0) {return {};}
        int average = mean * (rolls.size() + n);
        int missing_sum = average;        
        for (int roll: rolls) {missing_sum -= roll;} 
        
        if (missing_sum > 6 * n || missing_sum < n) {return {};} 
        // missing_sum can be made only of all 0's or all 1's
        vector<int> result(n, 0);
        for (int i = n; i >= 1; --i) {
            result[i-1] = missing_sum / i;
            missing_sum -= result[i-1];
        }

        return result;
    }
};
