//Time: 24 ms (83.89%), Space: 9 MB (79.01%) - LeetHub
class Solution {
public:
    void backt(vector<vector<int>>& vvi, vector<int>& vi, int d, int n) {
        if (d == vi.size()) {
            vvi.push_back(vi);
            return;
        }
        for (int i = d ? vi[d-1] + 1 : 1; i <= n; i++) {
            vi[d] = i;
            backt(vvi, vi, d + 1, n);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vvi;
        vector<int> vi(k);
        backt(vvi, vi, 0, n);
        return vvi;
    }
};
