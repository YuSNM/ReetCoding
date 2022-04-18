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