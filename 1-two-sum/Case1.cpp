//Time: 19 ms (60.43%), Space: 10.9 MB (44.72%) - LeetHub

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(size_t i = 0; i < nums.size(); i++) {
            if(map.count(nums[i])) 
                return {map[nums[i]], (int)i};
            map[target - nums[i]] = i;
        }
        return vector<int>();
    }
};
