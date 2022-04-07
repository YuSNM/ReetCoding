// Time: 58 ms (44.43%), Space: 89.7 MB (42.91%) - LeetHub
// BigO(N+M)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.size() + nums2.size());
        int i, j, k, k_max = v.size() + 1 >> 1;
        
        for(i = 0, j = 0, k = 0; i < nums1.size() && j < nums2.size() && k <= k_max;) 
            v[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        for(; i < nums1.size() && k <= k_max;) 
            v[k++] = nums1[i++];
        for(; j < nums2.size() && k <= k_max;) 
            v[k++] = nums2[j++];
        return (v[v.size() - 1>>1] + v[v.size()>>1]) / 2.0;
        
    }
};
