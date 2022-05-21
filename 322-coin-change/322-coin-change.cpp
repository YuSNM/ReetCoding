class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount)
            return 0;
        
        vector<int> v;
        vector<int> dp(amount+1);
        for (int coin : coins) 
            if (amount >= coin) {
                dp[coin] = 1;
                v.push_back(coin);
            }
        
        for (int i = 0; i <= amount; ++i) 
            for (int coin : v) 
                if (i >= coin && dp[i-coin]) 
                    if (dp[i])
                        dp[i] = min(dp[i], dp[i-coin] + 1);
                    else
                        dp[i] = dp[i-coin] + 1;
                
            
        return dp[amount] ? dp[amount] : -1;
    }
};