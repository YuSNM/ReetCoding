class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        int i = 1;
        while (++i < cost.size()) 
            cost[i] += min(cost[i-2], cost[i-1]);
        return min(cost[i-2], cost[i-1]);
    }
};