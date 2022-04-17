class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cnt = {0};
        
        for (int bit = 1, i_max;; bit<<=1) {
            i_max = cnt.size();
            for (int i = 0; i < i_max; i++) {
                if(i+bit > n) return cnt;
                cnt.push_back(cnt[i] + 1);
            }
        }
    }
};