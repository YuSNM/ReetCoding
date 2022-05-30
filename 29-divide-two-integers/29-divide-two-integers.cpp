class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool isPositive = (dividend >= 0 == divisor >= 0);
        
        long long de = abs(dividend);
        long long ds = abs(divisor);
        
        long long quotient = 0;
        
        while (de >= ds) {
            int q = 0;
            
            while (de > (ds << q+1))
                ++q;
            quotient += 1<<q;    
            de -= ds << q;
        }
        
        if (isPositive && quotient >= INT_MAX) 
            return INT_MAX;
        
        return isPositive ? quotient : -quotient;
    }
};