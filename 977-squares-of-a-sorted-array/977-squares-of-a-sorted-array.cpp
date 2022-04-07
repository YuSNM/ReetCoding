class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size());
        for(auto& i : nums) i*=i;
        
        int i = 0, j = nums.size() - 1, k = nums.size();
        while(i <= j)
            v[--k] = (nums[i] >= nums[j] ? nums[i++] : nums[j--]);
        
        return v;
    }
};