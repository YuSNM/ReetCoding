class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        int i, j;
        k %= nums.size();
        for(i = nums.size() - k, j = 0; i < nums.size(); ++i, ++j) 
            v[j] = nums[i];
        for(i = 0; j < nums.size();  ++i, ++j) 
            v[j] = nums[i];
        nums = v;
    }
};