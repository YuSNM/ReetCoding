class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (auto& str : strs) {
            int n0 = count(str.begin(), str.end(), '0');
            int n1 = str.size() - n0;
            
            for (int i = m; i >= n0; --i)
                for (int j = n; j >= n1; --j)
                    dp[i][j] = max(dp[i][j], dp[i - n0][j - n1] + 1);
        }
        
        return dp[m][n];
    }
};