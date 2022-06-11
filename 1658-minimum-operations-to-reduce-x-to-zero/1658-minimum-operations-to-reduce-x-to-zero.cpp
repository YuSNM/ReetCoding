class Solution {
    const int INF = 100001;
public:
    int minOperations(vector<int>& nums, int x) {
        int i = 0, j = nums.size();
        int sum = 0, ans = INF;
        
        while (i < j && sum + nums[i] <= x) 
            sum += nums[i++];
        
        
        while (1) {
            
            while (i < j && sum + nums[j - 1] <= x)
                sum += nums[--j];
            
            if (sum == x)
                ans = min(ans, i + (int)nums.size() - j);
            
            if (i == 0)
                break;
            sum -= nums[--i];
        }
        
        return ans != INF ? ans : -1;
    }
};