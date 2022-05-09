//Time: 0 ms (100.00%), Space: 6.4 MB (95.51%) - LeetHub

class Solution {
    
private:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()) {
            dfs(digits, "", 0);
        }
        return ans;
    }
    
    void dfs(string digits, string str, int d) {
        if (d == digits.size()) {
            ans.push_back(str);
            return;
        }
        
        for (auto& c : letters[digits[d] - '2']) 
            dfs(digits, str + c, d + 1);
        
    }
};
