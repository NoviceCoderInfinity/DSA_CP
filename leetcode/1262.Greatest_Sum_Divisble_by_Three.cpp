class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        map<int, vector<int>> dp;
        dp[0] = {}, dp[1] = {}, dp[2] = {};

        int sum = 0;
        for (int num: nums) {
            if (num % 3 == 0) dp[0].push_back(num);
            else if (num % 3 == 1) dp[1].push_back(num);
            else dp[2].push_back(num);
            sum += num;
        }

        if (sum % 3 == 0) return sum;

        sort(dp[1].begin(), dp[1].end());
        sort(dp[2].begin(), dp[2].end());
        int remove_rem_1; int remove_rem_2;

        // The core idea is that, if the remainder is 1 then it can be due to 
        // (3q+2) + (3p+2) = (3m+4) = (3n+1) aka two numbers with remainders 2
        // (3q+1) a single number with remainder 1
        if (sum % 3 == 1) {            
            if (dp[1].size() >= 1) remove_rem_1 = dp[1][0];
            else remove_rem_1 = sum; // this is to prevent max function from selecting this outcome
            if (dp[2].size() >= 2) remove_rem_2 = (dp[2][0] + dp[2][1]);
            else remove_rem_2 = sum; // this is to prevent max function from selecting this outcome
            return max(sum - remove_rem_1, sum - remove_rem_2);
        }
        // The core idea is that, if the remainder is 2 then it can be due to 
        // (3q+1) + (3p+1) = (3m+2) aka two numbers with remainders 1
        // (3q+2) a single number with remainder 2
        else if (sum % 3 == 2) {            
            if (dp[1].size() >= 2) remove_rem_1 = (dp[1][0] + dp[1][1]);
            else remove_rem_1 = sum; // this is to prevent max function from selecting this outcome
            if (dp[2].size() >= 1) remove_rem_2 = dp[2][0];
            else remove_rem_2 = sum; // this is to prevent max function from selecting this outcome
            return max(sum - remove_rem_1, sum - remove_rem_2);
        }
        return sum;
    }
};
