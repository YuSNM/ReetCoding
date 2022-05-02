//Time: 75 ms (5.02%), Space: 16.3 MB (57.28%) - LeetHub

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int N = nums.size(), i = 0, j;; swap(nums[i], nums[j])) {
            for (; i < N && !(nums[i] & 1); ++i);
            for (j = i + 1; j < N && nums[j] & 1; ++j);
            if (j >= N) 
                break;
        }
        return nums;
    }
};
