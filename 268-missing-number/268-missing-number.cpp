class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_map<int, int> m;
        
        for (int i : nums)
            ++m[i];
        
        int ans = -1;
        while (m[++ans]);
        
        return ans;
    }
};