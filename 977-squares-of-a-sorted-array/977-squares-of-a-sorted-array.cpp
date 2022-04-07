class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 1) return {nums[0]*nums[0]};
        vector<int> v(nums.size());
        
        int i = 0, j = nums.size() - 1, k = nums.size();
        nums[i]*=nums[i];
        nums[j]*=nums[j];
        while(i <= j) {
            if(nums[i] >= nums[j]){
                v[--k] = nums[i++];
                if(i < j) nums[i]*=nums[i];
            }
            else {
                v[--k] = nums[j--];
                if(i < j) nums[j]*=nums[j];
            }
            
        }
        
        
        return v;
    }
};