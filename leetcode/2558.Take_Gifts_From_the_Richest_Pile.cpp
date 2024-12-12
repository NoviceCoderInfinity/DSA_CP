class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--) {
            auto max_it = max_element(gifts.begin(), gifts.end());
            int pos = distance(gifts.begin(), max_it);
            gifts[pos] = floor(pow(gifts[pos], 0.5));
        }
        long long sum = 0 ;
        for (int gift: gifts) {
            sum += static_cast<long long>(gift);
        }
        return sum;
    }
};
