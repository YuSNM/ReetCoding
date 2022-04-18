//Time: 62 ms (72.48%), Space: 23.1 MB (53.25%) - LeetHub

class Solution {
public:
    bool validPalindrome(string s, int life = 1) {
        int i = -1;
        int j = s.size();
        
        while (++i < --j)            
            if(s[i] != s[j]) 
                return life-- ? validPalindrome(s.substr(i, j - i), life) || validPalindrome(s.substr(i + 1, j - i), life) : 0;
        return 1;
    }
};
