class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0, i_max = nums.size() / 2;; i++) 
            if(nums[i]==nums[i+i_max]) return nums[i];
        
    }
};