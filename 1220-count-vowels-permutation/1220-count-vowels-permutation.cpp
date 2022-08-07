
class Solution {
    const long long mod = 1e9+7;
public:
    int countVowelPermutation(int n) {
        long long arr[5] = {1, 1, 1, 1, 1}, temp[5];
        
        for (int i = 1; i < n; i++) {
            temp[0] = (arr[1] + arr[2] + arr[4])%mod;
            temp[1] = (arr[0] + arr[2])%mod;
            temp[2] = (arr[1] + arr[3])%mod;
            temp[3] = arr[2]%mod;
            temp[4] = (arr[2] + arr[3])%mod;
            arr[0] = temp[0];
            arr[1] = temp[1];
            arr[2] = temp[2];
            arr[3] = temp[3];
            arr[4] = temp[4];
        }
        return accumulate(begin(arr), end(arr), (long long)0) % mod;
    }
};