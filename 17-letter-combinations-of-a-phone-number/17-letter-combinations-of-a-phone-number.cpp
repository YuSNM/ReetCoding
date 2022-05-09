class Solution {
    
private:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()) {
            string buf(digits);
            dfs(digits, buf, 0);
        }
        return ans;
    }
    
    void dfs(string digits, string& buf, int d) {
        if (d == digits.size()) {
            ans.push_back(buf);
            return;
        }
        
        for (auto& c : letters[digits[d] - '2']) {
            buf[d] = c;
            dfs(digits, buf, d + 1);
        }
    }
};