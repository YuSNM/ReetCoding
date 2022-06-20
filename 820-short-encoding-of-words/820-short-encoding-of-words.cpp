class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        string temp;
        
        sort(words.begin(), words.end(), [] (const string& a, const string& b) {
            return a.size() > b.size();});
        
        for (string& s : words)
            ++m[s];
        
        for (string& s : words) {
            if (m[s] > 0)
                ans += s.size() + 1;
            
            for (int i = s.size() - 1; i >= 0; --i)
                if (m.count(temp = s.substr(i)))
                    m[temp] = 0;
        }
        
        return ans;
    }
};