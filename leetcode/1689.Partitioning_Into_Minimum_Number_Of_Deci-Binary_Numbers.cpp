class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(int i = 0; i<n.length(); i++) {
            if (res < n.at(i)) {res = n.at(i);}
        }
        res = res - '0';
        return res;
    }
};
