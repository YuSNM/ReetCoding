//Time: 47 ms (98.53%), Space: 23 MB (53.25%) - LeetHub

class Solution {
    bool check;
public:
    bool validPalindrome(string s) {
        bool ans = 0;
        int i = -1;
        int j = s.size();
        
        while (++i < --j)            
            if(s[i] != s[j]) 
                if(!check) {
                    check = 1;
                    return validPalindrome(s.substr(i, j - i)) || validPalindrome(s.substr(i + 1, j - i));
                }else
                    return 0;
        
        return 1;
    }
};
