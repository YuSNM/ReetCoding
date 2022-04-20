class Solution {
    int mem[46] = {1, 1};
public:
    int climbStairs(int n) {
        for (int i = 2; i <= n; i++) 
            mem[i] = mem[i-1] + mem[i-2];
        return mem[n];
    }
};