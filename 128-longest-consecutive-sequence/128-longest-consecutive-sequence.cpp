class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 1, cnt = 1;
        
        for (int i = 1; i < nums.size() ; i++) {
            if (nums[i-1] + 1 == nums[i]) {
                cnt++;
            }else if (nums[i-1] == nums[i])
                continue;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        
        return max(ans, cnt);
    }
};