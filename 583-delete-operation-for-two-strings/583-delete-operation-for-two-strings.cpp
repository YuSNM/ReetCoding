class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) 
                dp[i+1][j+1] = (word1[i] == word2[j] ? dp[i][j] + 1 : max(dp[i][j+1], dp[i+1][j]));
            
        return N + M - 2 * dp[N][M];
    }
};