// Hashing Solution
// Time Complexity: O(n)
// Space ComplexityL O(n)
// Result: Accepted
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set <int> elements(nums.begin(), nums.end());
        return elements.size() != nums.size();
    }
};
