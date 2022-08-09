class Solution {
    const int mod = 1e9+7;
    unordered_map<int, int> db;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans = 0;
        
        for (int num : arr) db[num] = 0;
        for (int num : arr)
            ans = (ans + func(num)) % mod;
        
        return ans;
    }
    long long func(int n) {
        if (db[n]) return db[n];
        
        int i;
        long long sum = 1;
        for (i = 2; i < (int)ceil(sqrt(n)); i++) 
            if (n % i == 0 && db.count(i) && db.count(n/i)) 
                sum = (sum + func(i) * func(n/i) * 2) % mod;
        if (db.count(i) && i * i == n)
            sum = (sum + func(i) * func(i)) % mod;
        return db[n] = sum;
    }
};