class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + --k, nums.end(), [] (int a, int b) {return a > b;});
        return nums[k];
    }
};