class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] ans = new int[nums.length];
        int lo = 0, hi = nums.length - 1;
        
        for (int i = 0; i < nums.length; i++) 
            if ((nums[i] & 1) == 1) 
                ans[hi--] = nums[i];
            else
                ans[lo++] = nums[i];
        
        return ans;
    }
}