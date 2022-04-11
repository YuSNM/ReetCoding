//Time: 16 ms (99.15%), Space: 14.1 MB (40.46%) - LeetHub

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> ans(M, vector<int>(N, 0));

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                int tx = i, ty = j + k;

                tx = (tx + ty / N) % M;
                ty %= N;
                ans[tx][ty] = grid[i][j];
            }    
        }
        return ans;
    }
};
