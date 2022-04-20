//Time: 0 ms (100.00%), Space: 5.7 MB (99.13%) - LeetHub

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0) return false;
        for (; n > 1; n >>= 1) 
            if (n & 1) 
                return false;
        return true;
    }
};
