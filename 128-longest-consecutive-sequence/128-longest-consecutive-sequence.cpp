class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> m;
        
        for (int i : nums)
            m[i] = 1;
        
        int ans = 0;
        for (auto& i : m) 
            if (m.count(i.first - 1) == 0 && i.second) {
                int cnt = 1;
                while (m.count(i.first+cnt) && m[i.first+cnt])
                    m[i.first+cnt]--, cnt++;
                ans = max(ans, cnt);
            }
        
        return ans;
    }
};