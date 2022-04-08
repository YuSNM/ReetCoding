//Time: 7 ms (74.07%), Space: 13.1 MB (12.64%) - LeetHub

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        prices.push_back(-1);
        for (int bef = 0, i = 1; i < prices.size(); i++) {
            if (prices[i - 1] > prices[i]) {
                ans += prices[i - 1] - prices[bef];
                bef = i;
            }
        }
        return ans;
    }
};
