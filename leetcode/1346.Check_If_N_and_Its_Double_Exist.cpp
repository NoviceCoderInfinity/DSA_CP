// Solution 1
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                if ((i != j) && (arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i])) {return true;}
            }
        }
        return false;
    }
};

// Solution 2
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zero_count = 0;
        set<int> evenSet;
        for (int num: arr) {
            if (num % 2 == 0) {evenSet.insert(num);}
            if (num == 0) {++zero_count;}
        }
        for (int num: arr) {
            if (evenSet.find(num * 2) == evenSet.end()) {continue;}
            else {
                if (num == 0 && zero_count == 1) {continue;}
                return true;
            }
        }
        return false;
    }
};

