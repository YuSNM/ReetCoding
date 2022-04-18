class Solution {
public:
    bool validPalindrome(string s, int life = 1, int i = -1, int j = -1) {
        if (j < 0) 
            j = s.size();
        while (++i < --j)            
            if(s[i] != s[j]) 
                return life-- ? validPalindrome(s, life, i - 1, j) || validPalindrome(s, life, i, j + 1) : 0;
        return 1;
    }
};