class Solution {
public:
    int mirrorReflection(int p, int q) {
        return (q / GCD(p, q) % 2) + (p / GCD(p, q) % 2 == 0);
    }
    int GCD(int a, int b) {
        return b ? GCD(b, a%b) : a;
    }
};