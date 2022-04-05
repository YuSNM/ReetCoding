//Time: 131 ms (41.50%), Space: 59.1 MB (38.72%) - LeetHub

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
