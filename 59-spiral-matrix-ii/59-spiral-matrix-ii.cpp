
class Solution {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> Matrix(n, vector<int>(n, 0));
        
        int x = 0;
        int y = 0;
        
        for(int i = 1, i_max = n * n, j = 0; i <= i_max; i++) {
            Matrix[x][y] = i;
            
            int next_x = x + dx[j];
            int next_y = y + dy[j];

            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || Matrix[next_x][next_y]) {
                j = (j + 1) % 4;
                next_x = x + dx[j];
                next_y = y + dy[j];
            }
            x = next_x;
            y = next_y;
        }
        return Matrix;
    }
};