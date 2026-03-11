// Approach 1
// input + output = 1111..11
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){return 1;}
        int pow_two=0;
        while(pow(2,pow_two)<=n){
            ++pow_two;
        }
        return (pow(2,pow_two)-n-1);
    }
};

// Approach 2
// Flip each bit iteratively
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){return 1;}
        int to_flip = n, flip_bit = 1;
        while (to_flip) {
            n = n ^ flip_bit;
            flip_bit = flip_bit << 1;
            to_flip = to_flip >> 1;
        }

        return n;
    }
};

// Approach 3
// Create a mask and flip all the bits at once
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){return 1;}
        int len = floor(log2(n)) + 1;
        int mask = (1 << len) - 1;

        return mask ^ n;
    }
};

// Approach 4  (Coolest Solution)
// HighestOneBit Approach
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){return 1;}
        int bitmask = n;
        bitmask |= (bitmask >> 1);
        bitmask |= (bitmask >> 2);
        bitmask |= (bitmask >> 4);
        bitmask |= (bitmask >> 8);
        bitmask |= (bitmask >> 16);

        return bitmask ^ n;
    }
};
