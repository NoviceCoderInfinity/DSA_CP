class Solution {
    public int m;
    public int n;
    public int val;
    public int color;

    private void bool_arr(int[][] image, int x, int y) {
        image[x][y] = color;
        if (x > 0 && image[x-1][y] == val) {bool_arr(image, x-1, y);}
        if (y > 0 && image[x][y-1] == val) {bool_arr(image, x, y-1);}
        if (x < m - 1 && image[x+1][y] == val) {bool_arr(image, x+1, y);}
        if (y < n - 1 && image[x][y+1] == val) {bool_arr(image, x, y+1);}
        return;
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        m = image.length; n = image[0].length; val = image[sr][sc]; this.color = color;
        if (val == color) {return image;}
        bool_arr(image, sr, sc);
        return image;
    }
}
