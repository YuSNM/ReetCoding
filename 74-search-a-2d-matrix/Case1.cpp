//Time: 3 ms (88.08%), Space: 9.5 MB (53.45%) - LeetHub


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int s = -1;
        int e = matrix.size();
        
        while (s + 1 < e) {
            int mid = s + (e - s) / 2;
            
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) s = mid;
            else e = mid;
        }
        
        if (s < 0 || matrix[s].back() < target) return false;
        
        vector<int>& ref = matrix[s];
        
        s = -1;
        e = ref.size();
        
        while (s + 1 < e) {
            int mid = s + (e - s) / 2;
            
            if (ref[mid] == target) return true;
            else if (ref[mid] < target) 
                s = mid;
            else 
                e = mid;
        }
        return false;
    }
};
