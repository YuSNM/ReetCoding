class Solution {
public:
    void backt(vector<string>& vs, string& s, vector<int> idx, int d) {
        if (d == idx.size()) {
            vs.push_back(s);
            return;
        }
        int i = idx[d];
        
        backt(vs, s, idx, d + 1);
            
        if (s[i] >= 'a') 
            s[i] -= 32;
        else 
            s[i] += 32;

        backt(vs, s, idx, d + 1);
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> vs;
        vector<int> idx;
        for (int i = 0; i < s.length(); i++) 
            if (!(s[i] >= '0' && s[i] <= '9')) 
                idx.push_back(i);
        backt(vs, s, idx, 0);
        return vs;
    }
};