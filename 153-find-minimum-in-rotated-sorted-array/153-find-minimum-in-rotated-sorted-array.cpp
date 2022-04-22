class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() <= nums.back()) 
            return nums.front();
        
        int s = 0;
        int e = nums.size() - 1;
        
        while (s < e) {
            int mid = s + (e-s)/2;
            
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            
            if (nums[mid] >= nums[0])
                s = mid + 1;
            else
                e = mid;
        }
        return nums[s];
    }
};