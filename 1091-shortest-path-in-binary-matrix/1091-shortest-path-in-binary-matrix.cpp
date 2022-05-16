class Solution {
    const vector<pair<int, int>> dir= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size() - 1;
        if (grid[0][0] || grid[N][N])
            return -1;
        
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (x == N && y == N)
                return grid[N][N];

            for (auto& p : dir) {
                int nx = x + p.first;
                int ny = y + p.second;
                if (nx < 0 || nx > N || ny < 0 || ny > N || grid[nx][ny])
                    continue;
                q.push({nx, ny});
                grid[nx][ny] = grid[x][y] + 1;
            }
        }
        
        return -1;
    }
};