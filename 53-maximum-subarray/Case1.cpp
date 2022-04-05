//Time: 84 ms (99.62%), Space: 67.7 MB (91.30%) - LeetHub
/*
ANALYSIS :-
    Time Complexity : BigO(N)
    Space Complexity :
*/
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
