// Solution 1: O(k) solution

class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        for (int i = nums.size(); i > nums.size() - k; ) {
            product *= nums[--i];
            if (!product) {break;}
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


// Solution 2: O(1) Solution
class ProductOfNumbers {
    vector<int> prefix_mul;
public:
    ProductOfNumbers() {
        prefix_mul = {1};
    }
    
    void add(int num) {
        if (num == 0) {prefix_mul = {1};}
        else {prefix_mul.push_back(num * prefix_mul.back());}
    }
    
    int getProduct(int k) {
        if (k >= prefix_mul.size()) {return 0;}
        return prefix_mul.back() / prefix_mul[prefix_mul.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
