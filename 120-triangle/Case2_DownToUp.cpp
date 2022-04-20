//Time: 3 ms (98.07%), Space: 8.6 MB (68.22%) - LeetHub

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for (int i = triangle.size() - 1, j; i > 0; i--) 
            for (j = 0; j < i; j++)
                triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
        
        return triangle[0][0];
    }
};
