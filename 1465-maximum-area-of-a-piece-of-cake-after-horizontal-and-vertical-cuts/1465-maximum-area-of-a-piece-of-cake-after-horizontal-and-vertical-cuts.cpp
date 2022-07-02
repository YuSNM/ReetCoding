class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(begin(horizontalCuts), end(horizontalCuts));
        int h_max = max(horizontalCuts.front(), h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); i++)
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i-1]);
        
        sort(begin(verticalCuts), end(verticalCuts));
        int w_max = max(verticalCuts.front(), w - verticalCuts.back());
        for (int i = 1; i < verticalCuts.size(); i++)
            w_max = max(w_max, verticalCuts[i] - verticalCuts[i-1]);
        
        return (int)(((long long)h_max * w_max) % (long long)(1e9+7));
    }
};