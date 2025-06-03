// Solution 1: Hashmap as Frequency Counter
// Time Complexity: O(N) + O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int min_freq = floor(nums.size() / 3);
        map<int, int> freq_counter;
        for (int num: nums) {
            freq_counter[num] += 1;
        }
        vector<int> result = {};
        for (const auto& pair: freq_counter) {
            if (pair.second > min_freq) {result.push_back(pair.first);}
        }
        return result;
    }
};


// Solution 2: Boyer-Moore Voting Algorithm
// Time Complexity: O(N) + O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {return {};}
        int count1 = 0, count2 = 0;
        int num1, num2;
        for (int n: nums) {
            if (count1 == 0 && num2 != n) {
                num1 = n;
                ++count1;
            }
            else if (count2 == 0 && num1 != n) {
                num2 = n;
                ++count2;
            }
            else if (num1 == n) {
                ++count1;
            }
            else if (num2 == n) {
                ++count2;
            }
            else {
                --count1;
                --count2;
            }
        }

        vector<int> result;
        count1 = 0, count2 = 0;

        for (int n: nums) {
            if (num1 == n) {++count1;}
            if (num2 == n) {++count2;}
        }

        int min_count = floor(nums.size() / 3);
        if (count1 > min_count) {result.push_back(num1);}
        if (count2 > min_count) {result.push_back(num2);}

        return result;
    }
};
