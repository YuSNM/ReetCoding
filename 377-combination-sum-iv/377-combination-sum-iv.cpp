class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        function<int(int)> comb = [&dp, &nums, &comb] (int target) {
            if (target == 0)
                return 1;
            if (dp[target] != -1)
                return dp[target];
            dp[target] = 0;
            for (int n : nums) 
                if (n <= target)
                    dp[target] += comb(target-n);
            return dp[target];
        };
        return comb(target);
    }
};