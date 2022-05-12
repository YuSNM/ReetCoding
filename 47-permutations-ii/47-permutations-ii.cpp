class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        do {
            ans.push_back(nums);
            nextPermutation(nums);
        } while (nums != ans[0]);
        
        return ans;
    }
    
    void nextPermutation(vector<int>& nums) {
        int last = nums.size();
        if (last < 2) 
            return;
        
        int i = last - 1, j = last;
        while (1) {
            if (--i < 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
            if (nums[i] < nums[i + 1]) {
                while (nums[i] >= nums[--j]);
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
    }
};