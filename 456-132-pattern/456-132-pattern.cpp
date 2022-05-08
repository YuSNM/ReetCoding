class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int _max = INT_MIN;
        stack<int> st;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (_max > nums[i])
                return true;
            while (!st.empty() && st.top() < nums[i]) {
                _max = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};