class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 0, j = nums.size() - 1, cnt = 0; i < j; i++)
            if (nums[i] > nums[i+1] && (cnt++ || i > 0 && i + 1 < j && nums[i-1] > nums[i+1] && nums[i] > nums[i + 2]))
                return 0;
        return 1;
    }
};