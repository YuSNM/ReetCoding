class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int top = 0;
        for (int i = 1, j; i < nums.size(); i++) 
            if (nums[top] < nums[i])
                nums[++top] = nums[i];
            else {
                for(j = top - 1; j >= 0 && nums[i] <= nums[j]; j--);
                nums[++j] = nums[i];
            }
        return top+1;
    }
};