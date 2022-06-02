class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        
        vector<vector<int>> trans(M, vector<int>(N));
        
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) 
                trans[j][i] = matrix[i][j];
        
        return trans;
    }
};