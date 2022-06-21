class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int i = 0, _max = heights.size() - 1, dif;
        
        priority_queue<int> q;
        
        for (; i < _max; i++) 
            if ((dif = heights[i+1] - heights[i]) > 0) {
                if (bricks < dif && !ladders)
                    return i;
                
                q.push(dif);
                bricks -= dif;
                
                if (bricks < 0) {
                    --ladders;
                    bricks += q.top();
                    q.pop();
                }
            }
        
        return _max;
    }
};