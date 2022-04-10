//Time: 4 ms (96.13%), Space: 7.5 MB (84.46%) - LeetHub

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpcnt(127, 0);
        int i = 0, bef = 0;
        int _max = 0;
        
        while(1) {
            if (i == s.size()) {
                _max = max(i - bef, _max);  //max 갱신
                return _max;
            }
            if (alpcnt[s[i]]) {
                _max = max(i - bef, _max);  //max 갱신
                
                do --alpcnt[s[bef++]];
                while (alpcnt[s[i]]);
                
            }
            
            ++alpcnt[s[i++]];
        }
    }
};
