class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpcnt(127, 0);
        int _max = 0, i = 0, bef = 0;
        for (; i < s.size(); ++alpcnt[s[i++]]) {
            _max = max(i - bef, _max);
            while (alpcnt[s[i]]) 
                --alpcnt[s[bef++]];
        }
        return max(i - bef, _max);
    }
};