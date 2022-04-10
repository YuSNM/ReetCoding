class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpcnt(127, 0);
        
        for (int i = 0, bef = 0, _max = 0;;++alpcnt[s[i++]]) 
            if (i == s.size()) {
                _max = max(i - bef, _max);  //max 갱신
                return _max;
            }
            else if (alpcnt[s[i]]) {
                _max = max(i - bef, _max);  //max 갱신
                do --alpcnt[s[bef++]];
                while (alpcnt[s[i]]);
            }
        
    }
};