class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        sort(begin(nums), end(nums));
        for_each(begin(nums), end(nums), [&] (int n) { ans += abs(n - nums[nums.size()/2]); });
        return ans;
    }
};