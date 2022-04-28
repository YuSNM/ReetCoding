class Solution {
private:
    vector<vector<bool>> visited;
    int N, M, K;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    
    bool Check(vector<vector<int>>& heights) {
        visited.assign(N, vector<bool>(M, 0));
        return Dfs(heights, 0, 0);
    }
    
    bool Dfs(vector<vector<int>>& heights, int x, int y) {
        
        if (x == N - 1 && y == M - 1) return true;
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || visited[next_x][next_y] || abs(heights[x][y] - heights[next_x][next_y]) > K)
                continue;
            if (Dfs(heights, next_x, next_y))
                return true;
        }
        return false;
    }
    
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int lo = 0, hi = 1e6;
        N = heights.size(), M = heights[0].size();
        
        while (lo < hi) {
            K = lo + (hi - lo) / 2;
            
            if (Check(heights))
                hi = K;
            else
                lo = K + 1;
        }
        
        return lo;
    }
};