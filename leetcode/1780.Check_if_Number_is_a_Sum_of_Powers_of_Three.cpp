// Solution 1
class Solution {
public:
    bool checkPowersOfThree(int n) {
        return check_recursively(1, 0, n);
    }

    bool check_recursively(int power_val, int exp_val, int n) {
        if (n == 0) {return true;}
        if (power_val > n) {return false;}
        int n_subb = n - power_val;
        power_val *= 3;
        ++exp_val;
        return (check_recursively(power_val, exp_val, n_subb) || check_recursively(power_val, exp_val, n));
    }
};
