//Time: 12 ms (98.16%), Space: 19.5 MB (80.05%) - LeetHub
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
