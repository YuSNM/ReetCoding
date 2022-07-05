//Time: 268 ms (52.47%), Space: 49.7 MB (52.56%) - LeetHub

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> m;
        for (int i : nums) 
            m[i] = 1;
        int ans = 0;
        for (auto& i : m) 
            if (i.second) {
                int n = i.first;
                int cnt = 0, sum = 0;
                while (m.count(n+cnt) && m[n+cnt])
                    m[n+cnt]--, cnt++;
                sum += cnt;
                
                cnt = 1;
                while (m.count(n-cnt) && m[n-cnt])
                    m[n-cnt]--, cnt++;
                sum += cnt - 1;
                ans = max(ans, sum);
            }
        
        return ans;
    }
};
