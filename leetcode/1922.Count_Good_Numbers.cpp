class Solution {
public:
    long long int MODULUS = 1e9+7;
    int countGoodNumbers(long long n) {
        long long int odd_pow = n / 2;
        long long int even_pow = (n + 1) / 2;

        long long int even_result = myPow(5, even_pow);
        long long int odd_result = myPow(4, odd_pow);

        return (even_result * odd_result) % MODULUS;
    }
    long long int myPow(long long int x, long long int n) {
        if (n == 0) {return 1;}
        long long int result = 1;
        x %= MODULUS;
        while (n > 0) {
            if (n % 2 == 1) {result = (result * x) % MODULUS;}
            x = (x * x) % MODULUS;
            n /= 2;
        }
        return result;
    }
};
