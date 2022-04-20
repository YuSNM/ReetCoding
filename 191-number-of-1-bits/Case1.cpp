//Time: 6 ms (15.22%), Space: 6.1 MB (48.64%) - LeetHub
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (; n; n >>= 1) 
            ans += n & 1;
        return ans;
    }
};
