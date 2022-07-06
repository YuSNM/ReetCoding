class Solution {
public:
    int fib(int n) {
        if (n < 3)
            return (n+1) / 2;
        return fib(n-1) + fib(n-2);
    }
};