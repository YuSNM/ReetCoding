class Solution {
    
    int box[31] = {0, 1, 1, };
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (box[n])
            return box[n];
        return box[n] = fib(n-1) + fib(n-2);
    }
};