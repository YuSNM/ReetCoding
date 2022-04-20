class Solution {
public:
    int rob(vector<int>& nums) {
        int i = 3, j = nums.size();
        if (j == 1)
            return nums[0];
        else if (j == 2) 
            return max(nums[0], nums[1]);
        
        for (nums[2] += nums[0]; i < nums.size(); i++) 
            nums[i] += max(nums[i-3], nums[i-2]);
            
        return max(nums[i-2], nums[i-1]);
    }
};