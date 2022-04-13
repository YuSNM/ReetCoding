class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], cnt = 0;
        for (auto& i : nums) {
            if(!cnt) 
                major = i;
            cnt += major != i ? -1 : 1;
        }
        return major;
    }
};