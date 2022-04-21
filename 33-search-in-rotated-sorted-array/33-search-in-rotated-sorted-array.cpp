class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = -1;
        int e = nums.size();
        bool check = !(nums.front() <= target);
        
        while (s + 1 < e) {
            int mid = s + (e - s) / 2;

            if (check ^ (nums[mid] < nums.front())) 
                (check ? s : e) = mid;
            else if (nums[mid] < target)
                s = mid;
            else if (nums[mid] > target) 
                e = mid;
            else
                return mid;
        }
        return -1;
    }
};