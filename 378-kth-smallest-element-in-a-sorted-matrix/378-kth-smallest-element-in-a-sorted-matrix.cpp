class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size()-1;
        int lo = matrix[0][0], hi = matrix[N][N];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = N;
            int lower_cnt = 0;
            for (int i = 0; i <= N; i++) {
                while (cur >= 0 && mid < matrix[i][cur])
                    --cur;
                lower_cnt += cur + 1;
            }
            lower_cnt < k ? lo = mid + 1 : hi = mid;
        }
        
        return lo;
    }
};