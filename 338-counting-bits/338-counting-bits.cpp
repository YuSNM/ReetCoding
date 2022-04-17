class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cnt = {0};
        
        for(int i = 0, i_max = cnt.size(), bit = 1; ;i++) {
            if(i==i_max) {
                i_max = cnt.size();
                bit <<= 1;
                i = 0;
            }
            if(i+bit > n) return cnt;
            cnt.push_back(cnt[i] + 1);
        }
        
    }
};