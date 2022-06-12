class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0, j = 0;
        unordered_map<int, bool> m;
        
        for (int n : nums) {
            if (m[n]) {
                while (nums[j] != n) {
                    m[nums[j]] = 0;
                    sum -= nums[j++];
                }
                ++j;
                continue;
            }
            m[n] = 1;
            sum += n;
            ans = max(ans, sum);
        }
            
        return ans;
    }
};