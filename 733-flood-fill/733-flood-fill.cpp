class Solution {
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    vector<vector<int>> visited;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int M = image.size();
        int N = image[0].size();
        int OldC = image[sr][sc];
        visited.assign(M, vector<int>(N));
        queue<pair<int, int>> q;
        
        for(q.push({sr, sc}); !q.empty(); q.pop())  {
            int x = q.front().first;
            int y = q.front().second;
            if(x < 0 || x >= M || y < 0 || y >= N || visited[x][y] || image[x][y] != OldC) continue; 
            
            visited[x][y] = 1;
            image[x][y] = newColor;
            for(int i = 0; i < 4; i++) 
                q.push({dx[i] + x, dy[i] + y});
        }
        
        return image;
    }
};