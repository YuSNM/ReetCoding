class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> v(26, 0);
        
        for (string& word : words2) {
            vector<int> buf = getAlpCnt(word);
            for (int i = 0; i < 26; i++)
                if (v[i] < buf[i])
                    v[i] = buf[i];
        }
    
        for (string& word : words1) {
            vector<int> buf = getAlpCnt(word);
            if (greaterThan(v, buf)) 
                ans.push_back(word);
        }
        return ans;
    }
    
    vector<int> getAlpCnt(string& str) {
        vector<int> buf(26, 0);
        for (char c : str)
            buf[c-'a']++;
        return buf;
    }

    bool greaterThan(vector<int>& a, vector<int>& b) {
        
        for (int i = 0; i < 26; i++)
            if (a[i] > b[i])
                return 0;
        return 1;
    }

};