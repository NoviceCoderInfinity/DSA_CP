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
