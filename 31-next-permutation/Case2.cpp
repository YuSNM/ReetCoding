// Time: 4 ms (72.76%), Space: 11.9 MB (93.43%) - LeetHub

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        auto first = nums.begin();
        auto last = nums.end();
        auto i = nums.end() - 1;

        while(i != first)       
            if(*i-- > *i) {  
                auto j = last;
                while (*i >= *--j);    
                iter_swap(i, j);       
                reverse(i + 1, last);   
                return;
            }
        reverse(first, last);
    }
};
