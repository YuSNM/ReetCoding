//Time: 0 ms (100.00%), Space: 6.9 MB (58.55%) - LeetHub

class Solution {
    int M, N;
public:
    void gameOfLife(vector<vector<int>>& board) {
        M = board.size(), N = board[0].size();
        
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) 
                if (board[i][j] % 2) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int x = i + dx;
                        if (0 > x || x == M) continue;

                        for (int dy = -1; dy <=1; dy++) {
                            int y = j + dy;
                            if (0 > y || y == N) continue;
                            board[x][y] += 2;
                        }
                    }
                    board[i][j] -= 2;
                }
                
            
        
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) {
                int cnt = board[i][j] / 2;
                if(board[i][j] % 2) {
                    if(cnt > 3 || cnt < 2) board[i][j] = 0;
                    else board[i][j] %= 2;
                }
                else if (cnt == 3) board[i][j] = 1;
                else board[i][j] = 0;
                
            }
        
                
    }
};
