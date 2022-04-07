//Time: 39 ms (57.38%), Space: 25 MB (81.08%) - LeetHub

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin() + k, nums.end());
    }
};
