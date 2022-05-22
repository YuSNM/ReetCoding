//Time: 6 ms (76.20%), Space: 6.3 MB (82.67%) - LeetHub

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) 
            ans += getCount(s, i, i) + getCount(s, i, i+1);
        return ans;
    }
    
    int getCount(string& s, int left, int right) {
        int cnt = 0;
        while (left >= 0 && right < s.length() && s[left--] == s[right++]) 
            ++cnt;
        return cnt;
    }
};
