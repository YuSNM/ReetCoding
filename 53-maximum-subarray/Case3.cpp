//Time: 261 ms (5.04%), Space: 67.7 MB (91.25%) - LeetHub

class Solution {
    
    struct data {
        int left, right, total, max;
        data(int l, int r, int t, int m) : left(l), right(r), total(t), max(m) {}
    };
    
public:
    
    data divconq(vector<int>& nums, int left, int right) {
        
        if(left==right) return {nums[left], nums[left], nums[left], nums[left]};

        int mid = left + right >> 1;

        data left_part = divconq(nums, left, mid);
        data right_part = divconq(nums, mid + 1, right);
        
        int l = max(left_part.left, left_part.total + right_part.left);
        int r = max(right_part.right, right_part.total + left_part.right);
        int t = left_part.total + right_part.total;
        int ma = max({left_part.max, left_part.right + right_part.left, right_part.max});
                                
        return {l, r, t, ma};
    }

    int maxSubArray(vector<int>& nums) {
        return divconq(nums, 0, nums.size() - 1).max;
    }
};
