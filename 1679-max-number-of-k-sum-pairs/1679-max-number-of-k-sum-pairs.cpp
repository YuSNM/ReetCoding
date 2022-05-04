class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (auto& i : nums)
            if (m.count(k - i) && m[k - i]) 
                --m[k - i], ans++;
            else
                ++m[i];

        return ans;
    }
};