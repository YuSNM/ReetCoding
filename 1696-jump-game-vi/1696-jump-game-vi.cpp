class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0];
        
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        
        for (int i = 1;; i++) {
            while (pq.top().second + k < i)
                pq.pop();
            if (i + 1 == nums.size())
                return pq.top().first + nums[i];
            pq.push({pq.top().first + nums[i], i});
        }
        
        return 0;
    }
};