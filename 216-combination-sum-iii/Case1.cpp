//Time: 0 ms (100.00%), Space: 6.5 MB (58.80%) - LeetHub

class Solution {
    vector<vector<int>> ans;
    int K;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> buf(K = k);
        
        dfs(buf, 0, n);
        return ans;
    }
    
    void dfs(vector<int>& buf, int d, int n) {
        if (d == K) {
            if (!n)
                ans.push_back(buf);
            return;
        }
        int i = (d ? buf[d-1] : 0);
        int i_max = n / (K-d) > 9 ? 9 : n / (K-d);
        
        while (++i <= i_max) {
            buf[d] = i;
            dfs(buf, d + 1, n - i);
        }
    }
};
