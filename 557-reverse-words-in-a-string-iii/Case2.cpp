//Time: 19 ms (52.43%), Space: 9.5 MB (89.61%) - LeetHub

class Solution {
public:
    string reverseWords(string s) {
        for(auto i = s.begin(), bef = s.begin();; ++i)
            if(i==s.end()) {
                reverse(bef, i);
                return s;
            }
            else if (*i == ' ') {
                reverse(bef, i);
                bef = i + 1;
            }
    }
};
