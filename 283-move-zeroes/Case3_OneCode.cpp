//Time: 26 ms (73.14%), Space: 19.3 MB (13.94%) - LeetHub

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int n) {return n;});
    }
};
