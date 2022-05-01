// Time: 2 ms (47.87%), Space: 6.3 MB (68.92%) - LeetHub

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = s.size() - 1, j = t.size() - 1;
        int back1 = 0, back2 = 0;
        
        while (1) {
            
            for (; i >= 0; --i) 
                if (s[i] == '#') 
                    ++back1;
                else if (back1) 
                    --back1;
                else
                    break;
            
            for (; j >= 0; --j) 
                if (t[j] == '#') 
                    ++back2;
                else if (back2) 
                    --back2;
                else
                    break;
            
            if (i < 0 && j < 0)
                return true;
            else if (i < 0 || j < 0)
                return false;
            
            if (s[i--] != t[j--]) 
                return false;
        }
        
        return true;
    }
};
