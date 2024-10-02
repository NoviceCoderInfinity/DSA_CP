class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) {return {};}
        vector<vector<int>> store;
        for (int i = 0; i < arr.size(); ++i) {
            store.push_back({arr[i], i});
        }
        sort(store.begin(), store.end());
        arr[store[0][1]] = 1;
        for (int i = 1; i < store.size(); ++i) {
            if (store[i-1][0] != store[i][0]) {
                arr[store[i][1]] = arr[store[i-1][1]] + 1;
            }
            else {
                arr[store[i][1]] = arr[store[i-1][1]];
            }
        }
        return arr;
    }
};
