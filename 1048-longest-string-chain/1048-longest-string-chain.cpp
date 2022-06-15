class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), [] (const string& s1, const string& s2) 
             { return s1.size() < s2.size();});
        
        for (auto str : words) {
            int _max = 0;
            for (int i = 0; i < str.size(); i++) {
                string subs = str.substr(0, i) + str.substr(i + 1);
                if (m.find(subs) != m.end()) 
                    _max = max(_max, m[subs]);
            }
            ans = max(ans,  m[str] = _max + 1);
        }
        return ans;
    }
};