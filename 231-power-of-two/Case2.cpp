//Time: 0 ms (100.00%), Space: 5.9 MB (70.59%) - LeetHub
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n & (n-1));
    }
};
