class Solution {
public:
    int maxArea(vector<int>& height) {
        int _max = 0;
        
        for(int left = 0, right = height.size()-1, area, h; left < right;) {
            
            h = min(height[left], height[right]);
            area = h * (right - left);
            _max = max(_max, area);
                            
            while(height[left] <= h && left < right) ++left;
            while(height[right] <= h && left < right) --right;
                            
        }
        
        return _max;
    }
};