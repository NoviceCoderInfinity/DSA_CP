class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int R_count = 0, L_count = 0;
        for (char move: moves) {
            if (move == '_') continue;
            move == 'R' ? ++R_count : ++L_count;
        }
        int blank = moves.size() - R_count - L_count;

        blank += abs(R_count - L_count);
        return blank;
    }
};
