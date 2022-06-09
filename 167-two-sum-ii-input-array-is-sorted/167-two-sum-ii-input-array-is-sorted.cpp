class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0;
        int j = numbers.size() - 1;
        
        while(1) {
            if (numbers[i] + numbers[j] < target)
                i = lower_bound(numbers.begin() + i + 1, numbers. begin() + j, target - numbers[j]) - numbers.begin();
            else if (numbers[i] + numbers[j] > target) 
                j = upper_bound(numbers.begin() + i + 1, numbers. begin() + j, target - numbers[i]) - numbers.begin() - 1;
            else
                return {i + 1, j + 1};
        }
    }
};