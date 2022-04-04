class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _max = -10000;
        int sum = 0;
        for(auto& i : nums) {
            sum += i;
            if(_max < sum) _max = sum;
            if(sum < 0) sum = 0;
        }
        return _max;
    }
};