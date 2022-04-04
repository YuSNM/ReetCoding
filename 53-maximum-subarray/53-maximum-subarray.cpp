class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _max = -10000;
        int sum = 0;
        for(auto& i : nums) {
            sum = sum < 0 ? i : sum + i;
            if(_max < sum) _max = sum;
        }
        return _max;
    }
};
    /*
        int divconq(vector<int>& nums, int left, int right) {
        if(left==right) return nums[left];
        int mid = left + right >> 1;
        int _max = max(divconq(nums, mid + 1, right), divconq(nums, left, mid));
        int left_max = -10000, right_max = -10000;

        for(int i = mid, left_sum = 0; left <= i; i--) {
            left_sum += nums[i];
            if(left_max < left_sum) left_max = left_sum;
        }
        for(int i = mid + 1, right_sum = 0; i <= right; i++) {
            right_sum += nums[i];
            if(right_max < right_sum) right_max = right_sum;
        }
        return max(_max, left_max + right_max);
    }

    int maxSubArray(vector<int>& nums) {
        return divconq(nums, 0, nums.size() - 1);
    }
    
    */