class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        for(int left = 0, right = nums.size(), mid;;) {
            mid = left + right >> 1;            
            if(nums[mid] > target) right = mid;         
            else if(nums[mid] < target) left = mid + 1;
            else return mid;
            if(left==right) return right;
        }
    }
};