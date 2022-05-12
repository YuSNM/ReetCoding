//Time: 5 ms (84.42%), Space: 8.4 MB (95.68%) - LeetHub

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        } while (nums != ans.front());
        
        return ans;
    }
};
