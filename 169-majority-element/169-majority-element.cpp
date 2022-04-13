class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], cnt = 0;
        for (auto& i : nums) {
            if(major != i) {
                if(--cnt < 0)
                    major = i, cnt = 1;
                continue;
            }  
            ++cnt;
        }
        return major;
    }
};