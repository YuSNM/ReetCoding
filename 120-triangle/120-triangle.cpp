class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int _min = 10000;
        
        for (int i = 0, i_max = triangle.size() - 1, j, j_max; i < i_max; i++) {
            triangle[i + 1][0] += triangle[i][0];
            
            for (j = 1, j_max = triangle[i].size(); j < j_max; j++)
                triangle[i + 1][j] += min(triangle[i][j - 1], triangle[i][j]);
            
            triangle[i + 1][j] += triangle[i][j - 1];
        }
        
        for (auto i : triangle.back())
            _min = min(_min, i);
        
        return _min;
    }
};