class Solution {
public:
    int maxArea(vector<int>& height) {
        int _max = 0;
        
        for(int left = 0, right = height.size()-1, area; left < right;) {
            if(height[left] < height[right]) {
                area = height[left] * (right-left);
                ++left;
            }else {
                area = height[right] * (right-left);
                --right;
            }
            
            if(area > _max) _max = area;
        }
        
        return _max;
    }
};