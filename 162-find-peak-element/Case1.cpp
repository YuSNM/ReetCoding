//Time: 0 ms (100.00%), Space: 8.8 MB (90.10%) - LeetHub
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i-1] > nums[i])
                return i-1;
        return 0;
    }
};
