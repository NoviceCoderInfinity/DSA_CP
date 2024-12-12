class Solution {
private:
    int m, n, val, color;
public:
    void bool_arr(vector<vector<int>>& image, int x, int y) {
        image[x][y] = color;
        if (x > 0 && image[x-1][y] == val) {bool_arr(image, x-1, y);}
        if (y > 0 && image[x][y-1] == val) {bool_arr(image, x, y-1);}
        if (x < m - 1 && image[x+1][y] == val) {bool_arr(image, x+1, y);}
        if (y < n - 1 && image[x][y+1] == val) {bool_arr(image, x, y+1);}
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(); n = image[0].size(); val = image[sr][sc]; this->color = color;
        if (val == color) {return image;}
        bool_arr(image, sr, sc);
        return image;
    }
};
