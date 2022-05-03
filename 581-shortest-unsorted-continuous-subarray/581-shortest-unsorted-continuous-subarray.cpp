class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int _min = 10001, _max = -10001;
        int lo = -1, hi = nums.size();
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (_min > nums[i])
                _min = nums[i];
            if (nums[i] > _min)
                lo = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (_max < nums[i])
                _max = nums[i];
            if (nums[i] < _max)
                hi = i;
        }        
        
        if (lo < 0)
            return 0;
        
        return hi - lo + 1;
    }
};