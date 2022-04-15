//Time: 7 ms (80.23%), Space: 13.8 MB (13.15%) - LeetHub

class Solution {
    const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int M, N;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        queue<tuple<int, int, int>> q;
        int _max = 0;
        
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    grid[i][j] = 1;
                }
        
        while(!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int d = get<2>(q.front());
            q.pop();
            if(x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 1) continue;
            grid[x][y] = 2;
            dp[x][y] = d;
            
            q.push({x-1, y, d+1});
            q.push({x+1, y, d+1});
            q.push({x, y-1, d+1});
            q.push({x, y+1, d+1});
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                _max = max(_max, dp[i][j]);
                if(grid[i][j] == 1) return -1;
            }
        
        return _max;
    }
};
