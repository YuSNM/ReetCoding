class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size());
        
        int i = 0, j = nums.size() - 1, k = nums.size();
        while(i <= j) {
            if(abs(nums[i]) >= abs(nums[j]))
                v[--k] = nums[i] * nums[i++];
            else 
                v[--k] = nums[j] * nums[j--];
        }
        
        
        return v;
    }
};