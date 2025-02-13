class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.end());

        int operation_counts = 0;

        while (min_heap.top() < k) {
            int x = min_heap.top(); min_heap.pop();
            int y = min_heap.top(); min_heap.pop();
            if (min(x, y) > (INT_MAX - max(x, y)) / 2) {min_heap.push(INT_MAX);}
            else {min_heap.push( min(x, y) * 2 + max(x, y) );}
            ++operation_counts;
        }

        return operation_counts;
    }
};
