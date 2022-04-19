//Time: 91 ms (66.33%), Space: 30.2 MB (63.19%) - LeetHub

class Solution {
    int M, N;
    const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        M = mat.size();
        N = mat[0].size();
        
        vector<vector<int>> Cnt(M, vector<int>(N, 0));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) 
                if (!mat[i][j]) 
                    q.push({i, j});
                
        while (!q.empty()) {
            int px = q.front().first;
            int py = q.front().second;

            q.pop();
            for(int d = 0; d < 4; d++) {
                int x = px + dx[d];
                int y = py + dy[d];
                
                if (x < 0 || x >= M || y < 0 || y >= N || !mat[x][y]) continue;
                
                q.push({x, y});
                mat[x][y] = 0;
                Cnt[x][y] = Cnt[px][py] + 1;
            }
            
        }
        
        return Cnt;
    }
};
