class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> cnt(s.size());
        int top = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            if (top >= 0 && s[i] == s[top]) {
                if (cnt[top] == k) 
                    top -= k - 1;
                else {
                    s[++top] = s[i];
                    cnt[top] = cnt[top - 1] + 1;
                }
            }
            else {
                s[++top] = s[i];
                cnt[top] = 2;
            }
                
        }
        return s.substr(0, top + 1);
    }
};