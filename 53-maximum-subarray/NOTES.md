int MidMax(vector<int>& nums, int left, int mid, int right) {

    int left_max = -10000, left_sum = 0;

    for (int i = mid; left <= i; i--) {
        left_sum += nums[i];
        left_max = max(left_max, left_sum);
    }

    int right_max = -10000, right_sum = 0;

    for (int i = mid + 1; i <= right; i++) {
        right_sum += nums[i];
        right_max = max(right_max, right_sum);
    }

    return left_max+right_max;
}

int divconq(vector<int>& nums, int left, int right) {
    if(left==right) return nums[left];

    int mid = left + right >> 1;

    int left_Max = divconq(nums, left, mid);
    int right_Max = divconq(nums, mid + 1, right);
    int Mid_Max = MidMax(nums, left, mid, right);
    
    return max({left_Max, right_Max, Mid_Max});
}

int maxSubArray(vector<int>& nums) {
    return divconq(nums, 0, nums.size() - 1);
}
