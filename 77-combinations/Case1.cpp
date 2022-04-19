//Time: 7 ms (98.69%), Space: 9 MB (79.01%) - LeetHub

class Solution {
public:
    void backt(vector<vector<int>>& vvi, vector<int>& vi, int n, int k) {
        if (k < 0) {
            vvi.push_back(vi);
            return;
        }
        for (int i = n; i > 0; i--) {
            vi[k] = i;
            backt(vvi, vi, i - 1, k - 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vvi;
        vector<int> vi(k);
        backt(vvi, vi, n, k - 1);
        return vvi;
    }
};
