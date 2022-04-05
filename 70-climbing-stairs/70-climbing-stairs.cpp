class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n+1, 1);
        for(int i = 0, j = n-2; i <= j; i++) 
            m[i+2] = m[i+1] + m[i];
        return m[n];
    }
};