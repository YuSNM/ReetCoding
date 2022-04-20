class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int _min = INT_MAX;
        
        for (int i = 0, j, i_max = triangle.size() - 1; i < i_max; i++) {
            triangle[i + 1][0] += triangle[i][0];
            
            for (j = 1; j < triangle[i].size(); j++)
                triangle[i + 1][j] += min(triangle[i][j - 1], triangle[i][j]);
            
            triangle[i + 1][j] += triangle[i][j - 1];
        }
        
        for (auto i : triangle.back())
            _min = min(_min, i);
        
        return _min;
    }
};