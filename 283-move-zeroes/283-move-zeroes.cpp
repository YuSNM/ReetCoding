class Solution {
public:
    static bool cmp(const int a, const int b) {
        return b==0;
    }
    void moveZeroes(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int j = 0;
        for(auto i : nums) 
            if(i) v[j++] = i; 
        nums = v;
    }
};