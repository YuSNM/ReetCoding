//Time: 4 ms (89.96%), Space: 9.5 MB (89.34%) - LeetHub


class Solution {
public:
    void backt(vector<string>& vs, string& s, int d) {

        int i = d;
        while(++i < s.length()) 
            if (!(s[i] >= '0' && s[i] <= '9')) 
                break;
        
        if (i == s.length()) {
            vs.push_back(s);
            return;
        }
        
        
        backt(vs, s, i);
            
        if (s[i] >= 'a') 
            s[i] -= 32;
        else 
            s[i] += 32;

        backt(vs, s, i);
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> vs;
        backt(vs, s, -1);
        return vs;
    }
};
