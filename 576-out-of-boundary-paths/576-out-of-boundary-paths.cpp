class Solution {
    vector<vector<vector<int>>> dp;
    int M, N;
    const int mod = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(M = m, vector<vector<int>>(N = n, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }
    
    long long dfs(int x, int y, int life) {
        if (life < 0)
            return 0;
        if (x < 0 || y < 0 || x >= M || y >= N) 
            return 1;
        if (dp[x][y][life] != -1)
            return dp[x][y][life];
        
        return dp[x][y][life] = (dfs(x+1, y, life - 1) + dfs(x-1, y, life - 1) + dfs(x, y+1, life - 1) + dfs(x, y-1, life - 1)) % mod;
    }
};