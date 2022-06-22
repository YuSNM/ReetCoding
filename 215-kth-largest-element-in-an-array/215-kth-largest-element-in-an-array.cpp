class Solution {
private:
    int k;
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k - 1;
        kth_quick_sort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int& p = nums[left++];
        
        while (left < right) {
            while (left <= right && nums[left] >= p) ++left;
            while (left <= right && nums[right] <= p) --right;
            
            if (left < right)
                swap(nums[left++], nums[right--]);
        }
        
        if (p < nums[right])
            swap(p, nums[right]);
        
        return right;
    }
    
    void kth_quick_sort(vector<int>& nums, int left, int right) {
        
        if (left < right) {
            
            int pivot = partition(nums, left, right);
            
            if (pivot == k) {
                return;
            }else if (pivot < k) {
                kth_quick_sort(nums, pivot + 1, right);
            }else {
                kth_quick_sort(nums, left, pivot - 1);
            }
            
            
        }
    }
};