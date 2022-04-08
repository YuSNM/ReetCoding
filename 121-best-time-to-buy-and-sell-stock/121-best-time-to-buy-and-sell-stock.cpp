class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, _min = INT_MAX;
        for(int i : prices) {
            _min = min(_min, i);
            ans = max(ans, i - _min);
        }
        return ans;
    }
};