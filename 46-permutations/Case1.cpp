//Time: 2 ms (79.72%), Space: 7.7 MB (56.08%) - LeetHub

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvi;
        
        do {
            vvi.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        } while (nums != vvi[0]);
        
        return vvi;
    }
};
