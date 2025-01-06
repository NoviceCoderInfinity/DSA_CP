//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for (int i = 0; i < arr.size() - 1; ++i) {
            int min_index = i, min_val = arr[i];
            for (int j = i; j < arr.size(); ++j) {
                if (arr[j] < min_val) {
                    min_index = j;
                    min_val = arr[j];
                }
            }
            arr.erase(arr.begin() + min_index);
            arr.insert(arr.begin() + i, min_val);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        obj.selectionSort(a);

        Array::print(a);
        cout << "~" << endl;
    }
}

// } Driver Code Ends
