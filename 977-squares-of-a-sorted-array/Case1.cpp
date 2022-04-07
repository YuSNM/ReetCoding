//Time: 49 ms (44.19%), Space: 25.9 MB (81.93%) - LeetHub

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& i : nums) i*=i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
