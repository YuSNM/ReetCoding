//Time: 0 ms (100.00%), Space: 6 MB (48.64%) - LeetHub


class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
