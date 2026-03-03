class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int res = (
            abs(coordinate1[0] - coordinate2[0]) +
            abs(coordinate1[1] - coordinate2[1])
        );
        return (res % 2 == 0) ? true : false;
    }
};
