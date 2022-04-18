class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;

        for (int last = nums.size(), i = last - 1, j; i > 0;)       
            if(nums[i] > nums[--i]) {  
                j = last;
                while (nums[i] >= nums[--j]);    
                swap(nums[i], nums[j]);       
                reverse(nums.begin() + i + 1, nums.end());   
                return;
            }
        reverse(nums.begin(), nums.end());
    }
};