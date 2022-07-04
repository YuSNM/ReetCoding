class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++) 
            if (ratings[i - 1] < ratings[i]) 
                dp[i] = dp[i - 1] + 1;
                
        for (int i = len - 2; i >= 0; i--) 
            if (ratings[i] > ratings[i+1]) 
                dp[i] = max(dp[i], dp[i + 1] + 1);
        
        return len + accumulate(begin(dp), end(dp), 0);
    }
};