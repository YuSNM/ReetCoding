//Time: 40 ms (19.89%), Space: 23.2 MB (89.05%) - LeetHub

class Solution {
    int _max = 0;
    int M, N;
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || M <= x || y < 0 || N <= y || !grid[x][y]) return 0;
        grid[x][y] = 0;
        return dfs(grid, x-1, y) + dfs(grid, x+1, y) + dfs(grid, x, y-1) + dfs(grid, x, y+1) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++)
                if(grid[i][j])
                    _max = max(_max, dfs(grid, i, j));
    
        return _max;
    }
};
