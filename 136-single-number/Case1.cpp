// Time: 19 ms (81.91%), Space: 17.2 MB (17.51%) - LeetHub
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int ans = 0;
        for(auto& i : nums) ans ^= i;
        return ans;
    }
};
