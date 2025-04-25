// Solution 1: Brute force 
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Result: TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit) {maxprofit = profit;}
            }
        }
        return maxprofit;
    }
};

// Solution 2: One Pass Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
// Result: Accepted
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minprice) {minprice = prices[i];}
            else if (prices[i] - minprice > maxprofit) {maxprofit = prices[i] - minprice;}
        }
        return maxprofit;
    }
};
