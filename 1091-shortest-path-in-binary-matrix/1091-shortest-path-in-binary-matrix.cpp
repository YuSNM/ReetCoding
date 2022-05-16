class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        for (int d = 1; !q.empty(); ++d) 
            for (int i = 0, len = q.size(); i < len; i++) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                if (x < 0 || y < 0 || x >= N || y >= N || grid[x][y])
                    continue;
                if (x == N - 1 && y == N - 1)
                    return d;
                grid[x][y] = 1;


                for (int i = -1; i <= 1; i++)
                    for (int j = -1; j <= 1; j++)
                        q.push({x + i, y + j});
            }
        
        return -1;
    }
};