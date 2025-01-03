//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        if (n < 4) {return 1;}
        
        int start = 1, end = n >> 1;
        int mid = start + (end - start)/2;
        
        while(start <= end) {
            mid = start + (end - start)/2;
            if (mid * mid > n) {end = mid - 1;}
            else{
                start = mid + 1;
            }
        }
        
        if (start * start > n) {return start - 1;}
        else {return start;}
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
