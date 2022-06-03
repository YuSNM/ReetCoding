class NumMatrix {
    
    int N, M;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        sum.assign(N+1, vector<int>(M+1));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                sum[i + 1][j + 1] = sum[i + 1][j] + matrix[i][j];
            for (int j = 1; j <= M; j++)
                sum[i + 1][j] += sum[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */