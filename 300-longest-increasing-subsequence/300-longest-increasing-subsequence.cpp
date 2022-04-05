class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LISv = {nums[0]};
        for(int i : nums)
            if (LISv.back() < i) LISv.push_back(i);
            else if (LISv.back() > i) {
                size_t idx = lower_bound(LISv.begin(), LISv.end(), i) - LISv.begin();
                LISv[idx] = min(LISv[idx], i);
            }
        return LISv.size();
    }
};