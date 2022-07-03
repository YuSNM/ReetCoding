//Time: 5 ms (48.51%), Space: 7.1 MB (75.45%) - LeetHub

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int ans = 2, i = 1;
        while (nums[i] == nums[0])
            if (++i >= nums.size())
                return 1;
        
        int sign = nums[i] > nums[0];
        
        while (++i < nums.size())
            if (sign && nums[i-1] > nums[i]) {
                ans++;
                sign = 0;
            }  else if (!sign && nums[i-1] < nums[i]) {
                ans++;
                sign = 1;
            }
        
        return ans;
    }
};
