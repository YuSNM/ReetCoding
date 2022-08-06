class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int p = minutesToTest / minutesToDie + 1;
        int ans = 0;
        for (int i = 1; i < buckets; i*=p)
            ans++;
        return ans;
    }
};