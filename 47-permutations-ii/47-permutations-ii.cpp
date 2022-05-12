class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
            nextPermutation(nums);
        } while (nums != ans[0]);
        
        return ans;
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) 
            return;
        
        int i = nums.size() - 1, j = nums.size();
        while (--i >= 0) 
            if (nums[i] < nums[i + 1]) {
                while (nums[i] >= nums[--j]);
                swap(nums[i], nums[j]);
                break;
            }
        
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};