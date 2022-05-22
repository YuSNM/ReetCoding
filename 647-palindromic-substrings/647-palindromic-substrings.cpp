class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1, right = i;
            
            while (right + 1 < s.length() && s[right] == s[right+1]) 
                ++right;
            
            ans += (right - left) * (right - left + 1) / 2;
            i = right++;
            while (left >= 0 && right < s.length() && s[left--] == s[right++])
                ++ans;
        }
        return ans;
    }
};