//Time: 196 ms (90.98%), Space: 47.9 MB (74.99%) - LeetHub
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
    
    int func1(vector<int>& v, int i) {
        for(int j : v) 
            if (j >= i)
                return j + 1;
        return -1;
    }
    bool func2(string& word) {
        int i = 0;
        for (auto c : word) 
            if ((i = func1(idx[c-'a'], i)) < 0)
                return 0;
        return 1;
    }
    
};
