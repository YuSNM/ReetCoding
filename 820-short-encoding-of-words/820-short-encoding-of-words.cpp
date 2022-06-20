class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        
        sort(words.begin(), words.end(), [] (const string& a, const string& b) {
            return a.size() > b.size();});
        
        for (string& s : words)
            ++m[s];
        
        for (string& s : words) {
            if (m[s] > 0)
                ans += s.size() + 1;
            
            string temp = "";
            for (int i = s.size() - 1; i >= 0; --i)
                if (m.count(temp = s[i] + temp))
                    m[temp] = 0;
        }
        
        return ans;
    }
};