class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for (int i = triangle.size() - 1, j, j_max; i > 0; i--) 
            for (j = 0, j_max = triangle[i].size() - 1; j < j_max; j++)
                triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
        
        return triangle[0][0];
    }
};