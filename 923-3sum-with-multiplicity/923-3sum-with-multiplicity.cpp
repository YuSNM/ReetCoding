
class Solution {
    const int mod = 1000000007;
    int HashT[301];
public:
    int Combi(long long n, int r) {
        for(int i = n - 1, f = 2; f <= r; i--, f++) 
            n = n * i / f;
        return n % mod;
    } 

    int func(vector<int>& arr, int target, int d, int start) {
        if (d == 1) return target >= start ? HashT[target] : 0;
        else if (d == 0) return target == 0;
        long long ans = 0;
        int i, i_max;
        for (i = start, i_max = target / d; i <= i_max; i++) {
            if (HashT[i])
                for (int j = 1; j <= d; j++) 
                    if(HashT[i] >= j) 
                        ans = (ans + func(arr, target - i * j, d - j, i + 1) * Combi(HashT[i], j))% mod;
        }
        return ans;
    }

    int threeSumMulti(vector<int>& arr, int target) {
        for(auto& i : arr) ++HashT[i];
        return func(arr, target, 3, 0);
    }
};