class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = -1;
        int e = nums.size();
        
        if (nums.front() <= target) 
            while (s + 1 < e) {
                int mid = s + (e - s) / 2;
                
                if (nums[mid] < nums.front()) 
                    e = mid;
                else if (nums[mid] < target)
                    s = mid;
                else if (nums[mid] > target) 
                    e = mid;
                else
                    return mid;
            }
        else if (target <= nums.back())
            while (s + 1 < e) {
                int mid = s + (e - s) / 2;
                
                if (nums[mid] > nums.back()) 
                    s = mid;
                else if (nums[mid] < target)
                    s = mid;
                else if (nums[mid] > target) 
                    e = mid;
                else
                    return mid;
            }
        else return -1;
                
        return -1;
    }
};