// 이전 높이 이하는 물 넓이 계산 필요 없이 넘겨주어 효율성을 높임
//Time: 100 ms (77.17%), Space: 59.1 MB (38.72%) - LeetHub

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
