class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(nums.empty()) return ans;
        
        int s = 0;
        int e = nums.size();
        while (s < e) {
            int mid = s + (e-s) / 2;
            if (nums[mid] < target) s = mid + 1;
            else e = mid;
        }
        if (s >= nums.size() || nums[s] != target) return ans;
        ans[0] = s;
        e = nums.size();
        while (s < e) {
            int mid = (s + e) >> 1;
            if (nums[mid] <= target) s = mid + 1;
            else e = mid;
        }
        ans[1] = e - 1;
        return ans;
    }
};