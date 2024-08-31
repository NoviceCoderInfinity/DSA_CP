#include <bits/stdc++.h>
using namespace std;

vector<int>sums; int final_depth;
    void iterative_summer(vector<int>& nums, int curr_sum = 0, int curr_level = 1, int pos = 1) {
        if (curr_level > final_depth) {sums.push_back(curr_sum); return;}
        int pos_1 = curr_level * 10 + (pos * 2 - 1);
        int pos_2 = curr_level * 10 + (pos * 2);
	bool has_no_child = true;
	cout << "\n\nCurrent Level " << curr_level << " Curr Sum " << curr_sum << " pos_1 " << pos_1 << " pos_2 " << pos_2 << endl;
        for (auto num: nums) {
            if (num / 10 == pos_1) {
		cout << "Adding the number " << num%10 << " at " << pos_1 << " sum becomes " << curr_sum+num%10 << endl;
                iterative_summer(nums, curr_sum+num%10, curr_level+1, pos_1%10);
		has_no_child = false;
            }
            else if (num / 10 == pos_2) {
		cout << "Adding the number " << num%10 << " at " << pos_2 << " sum becomes " << curr_sum+num%10 << endl;
                iterative_summer(nums, curr_sum+num%10, curr_level+1, pos_2%10);
                return;
            }
	    if (num / 10 > pos_2 && has_no_child) {
		sums.push_back(curr_sum); return;
 	    }
        }
        if (has_no_child) {
		sums.push_back(curr_sum); return;
	}
    }

    int pathSum(vector<int>& nums) {
        final_depth = nums.back() / 100;
        iterative_summer(nums);
        int result = 0;
        for(int sum: sums) {result += sum;}
        return result;
    }

int main() {
	vector<int> nums = {116,212,313,327,419,428};
	int result = pathSum(nums);
	cout << result << endl;
}
