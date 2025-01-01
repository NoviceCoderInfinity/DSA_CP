class Solution {
public: 
	int setBit(int n) {
        	int position = 0;
	        while ((n & (1 << position)) != 0) {
        	    ++position;
	        }
		n = n | (1 << position);
		return n;
	}
};
