//Time: 28 ms (67.00%), Space: 19.6 MB (7.03%) - LeetHub

/*
ANALYSIS :
    Time Complexity : BigO(N)
    Space Complexity : BigO(N)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int j = -1;
        for(auto i : nums) 
            if(i) v[++j] = i; 
        nums = v;
    }
};
