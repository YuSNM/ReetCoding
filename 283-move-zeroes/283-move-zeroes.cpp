class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int j = 0;
        for(auto i : nums) 
            if(i) v[j++] = i; 
        nums = v;
    }
};