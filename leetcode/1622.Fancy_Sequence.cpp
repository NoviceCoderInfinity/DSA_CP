class Fancy {
public:
    vector<long long> arr;
    long long mul = 1, add = 0;
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        long long normalized = ((val - add) % MOD + MOD) % MOD;
        normalized = (normalized * modInverse(mul)) % MOD;
        arr.push_back(normalized);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;

        long long res = (arr[idx] * mul % MOD + add) % MOD;
        return res;
    }
};
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
