class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& evs) {
        
        sort(evs.begin(), evs.end(), [] (const vector<int>& a, const vector<int>& b)->bool {
            if (a[0] < b[0])
                return 1;
            else if (a[0] > b[0])
                return 0;
            else
                return a[1] > b[1];
        });
        
        vector<int> dp = {evs[0][1]};
        
        for (auto i = evs.begin(); i != evs.end(); i++) {
            auto j = lower_bound(dp.begin(), dp.end(), i->back());
            
            if (j != dp.end())
                *j = i->back();
            else
                dp.push_back(i->back());
        
        }
        
        return dp.size();
    }
};