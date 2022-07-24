class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        
        while (i < matrix.size() && ~j) 
            if (target == matrix[i][j])
                return true;
            else
                target > matrix[i][j] ? i++ : j--;
        
        return false;
    }
};