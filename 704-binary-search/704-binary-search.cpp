class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int left = 0, mid, right = nums.size() - 1; left <= right;) {
            mid = left + right >> 1;
            
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        }
        return -1;
    }
};