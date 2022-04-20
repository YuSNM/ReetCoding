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