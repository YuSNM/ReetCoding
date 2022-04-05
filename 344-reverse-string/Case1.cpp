//Time: 27 ms (64.04%), Space: 23.1 MB (93.80%) - LeetHub
/*
ANALYSIS :
    Time Complexity : BigO(N)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(size_t i = 0, j = s.size() - 1; i < j; i++, j--) 
            swap(s[i], s[j]);
    }
};
