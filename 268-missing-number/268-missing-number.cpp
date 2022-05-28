class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(10001);
        
        int ans = 0;
        while (nums[ans] == ans)
            ++ans;
        
        return ans;
    }
};