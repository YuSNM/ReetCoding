class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int h = 0; h < numRows; h++) {
            ans[h].assign(h+1, 1);
            for (int i = 1; i < h; i++) 
                ans[h][i] = ans[h-1][i-1] + ans[h-1][i];
        }
        return ans;
    }
};