//Simulation Solution
class Solution {
public:
    string reverse(string x) {
        int left = 0, right = x.size() - 1;
        while(left < right) {
            swap(x[left], x[right]);
            ++left; --right;
        }
        return x;
    }

    string inverse(string x) {
        string inv = "";
        for (char c: x) {
            if (c == '1') {inv += '0';}
            else {inv += '1';}
        }
        return inv;
    }

    char findKthBit(int n, int k) {
        map<int, string> dp = { {1, "0"} };
        for (int i = 2; i <= n; ++i) {
            string tmp = dp[i-1] + "1" + reverse(inverse(dp[i-1]));
            dp[i] = tmp;
        }
        return dp[n][k-1];
    }
};

// Recursive Solution
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {return '0';}
        int len = pow(2, n) - 1;
        int mid = len/2 + 1;
        if (k < mid) {return findKthBit(n-1, k);}
        else if (k == mid) {return '1';}
        else {
            int index_dash = len - k + 1;
            char bit = findKthBit(n-1, index_dash);
            return (bit == '0') ? '1' : '0';
        }
    }
};
