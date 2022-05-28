//Time: 64 ms (5.13%), Space: 18 MB (20.98%) - LeetHub

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(10001);
        
        int ans = 0;
        while (nums[ans] == ans)
            ++ans;
        
        return ans;
    }
};
