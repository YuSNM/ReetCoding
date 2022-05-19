class Solution {
    vector<vector<int>> cnt;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int M, N;
public:
    
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        
        int& ret = cnt[x][y];
        if (ret) 
            return ret;
        ret = 1;
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && matrix[next_x][next_y] > matrix[x][y])
                ret = max(ret, dfs(matrix, next_x, next_y) + 1);
        }
        
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        M = matrix.size();
        N = matrix[0].size();
        cnt.assign(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) 
                ans = max(ans, dfs(matrix, i, j));
        
        return ans;
    }
};