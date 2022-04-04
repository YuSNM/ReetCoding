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