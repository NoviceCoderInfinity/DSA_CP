class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long sum = 0;

        for (int num: nums) {
            int found_divisor = 0;

            for (int divisor = 2; divisor * divisor <= num; ++divisor) {
                if (num % divisor == 0) {
                    if (found_divisor == 0) {found_divisor = divisor;}
                    else {found_divisor = 0; break;}
                }
            }

            if (found_divisor > 0 && found_divisor != num / found_divisor) {
                sum += (1 + num + found_divisor + num / found_divisor);
            }
        }

        return sum;
    }
};
