class Solution {
    vector<vector<int>> ans;
    vector<int> buf;
public:
    
    void backt(vector<int>& nums, int d) {
        
        if (d == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = d; i < nums.size(); i++) {
            swap(nums[d], nums[i]);
            backt(nums, d + 1);
            swap(nums[d], nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backt(nums, 0);
        return ans;
    }
};