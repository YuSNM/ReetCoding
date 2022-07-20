class Solution {
    
private:
     vector<vector<int>> idx;
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        idx.assign(26, vector<int>());
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) 
            idx[s[i] - 'a'].push_back(i);
        
        
        for (auto& word : words) 
            ans += func2(word);
        
        return ans;
    }
    bool func2(string& word) {
        int i = -1;
        for (auto c : word) {
            auto it = upper_bound(idx[c-'a'].begin(), idx[c-'a'].end(), i);
            if (it == idx[c-'a'].end())
                return 0;
            i = *it;
        }
        return 1;
    }
    
};