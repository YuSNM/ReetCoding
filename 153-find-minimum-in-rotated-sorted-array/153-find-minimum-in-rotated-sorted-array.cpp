class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() <= nums.back()) 
            return nums.front();
        
        int s = 0;
        int e = nums.size() - 1;
        const int left_min = nums[0];
        
        while (s < e) {
            int mid = s + (e-s)/2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            else if (nums[mid] >= left_min)
                s = mid + 1;
            else
                e = mid;
        }
        return nums[s];
    }
};