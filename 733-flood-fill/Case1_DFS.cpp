//Time: 15 ms (42.74%), Space: 14 MB (80.69%) - LeetHub


class Solution {
    const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int NewC, OldC;
public:
    void dfs(vector<vector<int>>& image, int sr, int sc) {
        image[sr][sc] = NewC;
        for(int i = 0; i < 4; i++) {
            int x = dx[i] + sr;
            int y = dy[i] + sc;
            if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != OldC) continue;
            dfs(image, x, y);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        NewC = newColor;
        OldC = image[sr][sc];
        dfs(image, sr, sc);
        return image;
    }
};
