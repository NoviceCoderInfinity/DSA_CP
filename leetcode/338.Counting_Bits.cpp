// Linear + Log(n) Solution
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Result: Accepted
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> soln;
        for (int i = 0; i <= n; ++i) {
            if(i==0||i==1){soln.push_back(i); continue;}
            int temp=i; short cnt=0;
            while(temp!=1){
                if(temp%2==0){
                    temp=temp>>1;
                    continue;
                }
                temp=temp-1;
                ++cnt;
                }
            soln.push_back(++cnt);
        }
        return soln;
    }
};




// Linear Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
class Solution {
public:
    vector<int> countBits(int n) {
        if (n==0) {return {0};}
        vector<int> result(n+1, 0);
        result[1] = 1;
        for (int i = 2; i < n+1; ++i) {
            if (i%2==0) {result[i] = result[i/2];}
            else {
                result[i] = result[i/2] + 1;
            }
        }
        return result;
    }
};
