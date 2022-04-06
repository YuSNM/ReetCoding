#define MOD 1000000007
class Solution {
    int HashT[301];
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1000000007;
        int ans = 0;
        for(int i = 1; i < arr.size(); ++i) {
            if(target < arr[i]) continue;
            ans = (ans + HashT[target - arr[i]]) % mod;
            for(int j = 0; j < i; ++j) 
                ++HashT[arr[i] + arr[j]];
        }
        return ans;
    }
};