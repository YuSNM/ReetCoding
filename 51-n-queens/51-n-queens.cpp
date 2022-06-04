class Solution {
    
private:
    int N;
    vector<vector<string>> ans;
    vector<string> board;
public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        N = n;
        
        backtrac(0);
        return ans;
    }
    

    void backtrac(int x) {
        if (x == N) {
            ans.push_back(board);
            return;
        }
        
        for (int i = 0; i < N; i++) {
            if (invalid(x, i))
                continue;
            
            board[x][i] = 'Q';
            backtrac(x + 1);
            board[x][i] = '.';
        }
    }
    
    bool invalid(int x, int y) {
        
        for (int i = 0; i < x; i++)
            if (board[i][y] == 'Q')
                return 1;
        for (int i = 1, j = min(x, y); i <= j; i++)
            if (board[x - i][y - i] == 'Q')
                return 1;
        for (int i = 1, j = min(x, N-1-y); i <= j; i++)
            if (board[x - i][y + i] == 'Q')
                return 1;
        return 0;
    }
    
};