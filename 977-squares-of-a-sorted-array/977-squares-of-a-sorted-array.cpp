class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size());
        
        for(int p = nums.size(), left = 0, right = nums.size() - 1; p > 0;) {
            if(abs(nums[left]) >= abs(nums[right]))
                v[--p] = nums[left] * nums[left++];
            else 
                v[--p] = nums[right] * nums[right--];
        }
        
        
        return v;
    }
};