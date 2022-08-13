class Solution {

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> DB;
        vector<int> ans;
        int wordCnt = words.size();
        int wordLen = words[0].size();
        int totalLen = wordCnt * wordLen;
        
        for (string& s : words)
            DB[s]++;
        
        for (int i = 0, i_max = s.size() - totalLen; i <= i_max; i++) 
            if ([&totalLen, &wordLen, &s, &DB] (int i) { 
                unordered_map<string, int> remainWord(DB);
                for (int j = 0; j < totalLen; j += wordLen) {
                    string subs = s.substr(i + j, wordLen);
                    if (!remainWord.count(subs) || --remainWord[subs] < 0)
                        return false;
                }
                return true;
            }(i))
                ans.push_back(i);
        
        
        return ans;
    }
};