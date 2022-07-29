class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string pat = makePat(pattern);
        
        for (string& word : words) {
            string wpat = makePat(word);
            if (wpat == pat)
                ans.push_back(word);
        }
        return ans;
    }
    
    string makePat(string& str) {
        vector<int> db(26, 0);
        string pdb;
        for (int i = 0, j = 1; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (db[idx] == 0) 
                db[idx] = j++;
            pdb.push_back(db[idx]);
        }
        return pdb;
    }
};