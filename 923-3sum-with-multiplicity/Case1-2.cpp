//Time: 1378 ms (14.97%), Space: 10.8 MB (20.41%) - LeetHub

class Solution {
    const int mod = 1000000007;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        unordered_map<int, int> um;
        for(int i = 1; i < arr.size(); ++i) {
            ans = (ans + um[target - arr[i]]) % mod;
            for(int j = 0; j < i; ++j) 
                ++um[arr[i] + arr[j]];
        }
        return ans;
    }
};
