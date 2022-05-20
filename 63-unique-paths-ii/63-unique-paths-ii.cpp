class Solution {
    int M, N;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        M = obstacleGrid.size();
        N = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] || obstacleGrid[M-1][N-1])
            return 0;
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        dp[0][0] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x + 1 < M) {
                if(!obstacleGrid[x+1][y]) {
                    q.push({x+1, y});
                    obstacleGrid[x+1][y] = 1;
                }
                dp[x+1][y] += dp[x][y];
            }
            if (y + 1 < N) {
                if(!obstacleGrid[x][y+1]) {
                    q.push({x, y+1});
                    obstacleGrid[x][y+1] = 1;
                }
                dp[x][y+1] += dp[x][y];
            }
        }
        
        return dp[M-1][N-1];
    }
};