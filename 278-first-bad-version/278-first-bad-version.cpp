// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int left = 1;
        unsigned int mid;
        unsigned int right = n;
        
        while(left < right) {
            mid = left + right >> 1;
            if(isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};