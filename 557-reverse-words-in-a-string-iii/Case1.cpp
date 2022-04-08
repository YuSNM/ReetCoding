//Time: 10 ms (96.33%), Space: 9.9 MB (40.30%) - LeetHub

class Solution {
public:
    string reverseWords(string s) {
        vector<string::iterator> idx;

        for(auto c = s.begin();; ++c)
            if(c==s.end()) {
                idx.push_back(c);
                break;
            }
            else if (*c == ' ')
                idx.push_back(c);

        auto bef = s.begin();
        for(auto& i : idx) {
            reverse(bef, i);
            bef = i + 1;
        }
        return s;
    }
};
