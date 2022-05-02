// Time: 81 ms (85.41%), Space: 20 MB (87.11%) - LeetHub

class Solution {
public:  
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0, sum = 0, last_i = INT_MIN; i < nums.size(); i++) {
            if (last_i == nums[i])
                continue;
            sum = -nums[i];
            last_i = nums[i];
            for (int j = i + 1, k = nums.size() - 1, last_j = INT_MIN; j < k;) 
                if (nums[j] + nums[k] < sum) 
                    ++j;
                else if (nums[j] + nums[k] > sum)
                    --k;
                else {
                    if (last_j != nums[j])
                        ans.push_back({nums[i], last_j = nums[j], nums[k]});
                    ++j, --k;
                }
            
        }
        
        return ans;
    }
};
