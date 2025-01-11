//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if (l >= r) return;
        int mid_point = l + (r - l) / 2;

        mergeSort(arr, l, mid_point);
        mergeSort(arr, mid_point + 1, r);

        vector<int> temp;
        int i = l, j = mid_point + 1;

        while (i <= mid_point && j <= r) {
                if (arr[i] <= arr[j]) {temp.push_back(arr[i++]);}
                else {temp.push_back(arr[j++]);}
        }

        while (i <= mid_point) {temp.push_back(arr[i++]);}
        while (j <= r) {temp.push_back(arr[j++]);}

        for (int k = 0; k < temp.size(); ++k) {arr[l+k] = temp[k];}
        return;
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
