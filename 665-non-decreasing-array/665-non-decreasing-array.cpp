class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int idx = -1;
        for (int i = 0, j = nums.size() - 1, cnt = 0; i < j; i++)
            if (nums[i] > nums[i+1]) {
                if (cnt++)
                    return 0;
                idx = i;
            }
        
        if (idx > 0 && idx + 2 < nums.size() && nums[idx-1] > nums[idx+1] && nums[idx] > nums[idx + 2])
            return 0;
        return 1;
    }
};