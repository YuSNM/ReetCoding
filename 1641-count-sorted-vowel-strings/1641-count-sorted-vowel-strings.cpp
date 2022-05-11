class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 4; j++) 
                for (int k = j + 1; k < 5; k++) 
                    dp[j] += dp[k];
            
        return dp[0];
    }
};