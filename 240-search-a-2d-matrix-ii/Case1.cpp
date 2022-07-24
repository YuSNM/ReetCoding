class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& v : matrix) {
            if (v.back() < target)
                continue;
            if (*lower_bound(v.begin(), v.end(), target) == target)
                return true;
            if (v.front() > target)
                return false;
        }
        return false;
    }
};
