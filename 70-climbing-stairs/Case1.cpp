//Time: 0 ms (100.00%), Space: 5.7 MB (97.27%) - LeetHub
class Solution {
    int mem[46] = {1, 1};
public:
    int climbStairs(int n) {
        for (int i = 2; i <= n; i++) 
            mem[i] = mem[i-1] + mem[i-2];
        return mem[n];
    }
};
