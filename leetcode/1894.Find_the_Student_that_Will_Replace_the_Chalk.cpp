// Simulation Solution
// Result : TLE
// Time Complexity: O(n); multiple iterations
// Space Compexity: O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(1) {
            for(int i = 0; i < chalk.size(); ++i) {
                k -= chalk[i];
                if (k < 0) {return i;}
            }
        }
    }
};


// Two Pass Solution
// Result: Accepted
// Time Complexity: O(n); Two passes in worst case
// Space Complexity: O(n)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long chalk_usage_sum = 0;
        for (int chalk_usg: chalk) { chalk_usage_sum += static_cast<long long>(chalk_usg); }
        k %= chalk_usage_sum;
        if (k == 0) {return 0;}
        int student_iter = 0;
        while(student_iter < chalk.size() && chalk[student_iter] <= k) {
            k -= chalk[student_iter++];
        }
        return student_iter;
    }
};


// Effectively One Pass + Binary Search
// Result: Accepted
// Time Complexity: O(n); Effectively O(1*n) + O(logn)
// Space Complexity: O(n)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long> prefix_sum(chalk.begin(), chalk.end());
        for (int i = 1; i < chalk.size(); ++i) {prefix_sum[i] += prefix_sum[i-1];}

        k %= prefix_sum.back();

        return find_index_binary_search(prefix_sum, k);
    }
private:
    int find_index_binary_search(vector<long>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= k) {low = mid + 1;}
            else {high = mid;}
        }
        return high;
    }
};
