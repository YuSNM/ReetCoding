/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int lo = 10001, int hi = 0) {
        if (lo == 10001) 
            lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            TreeNode* node = new TreeNode(nums[mid], sortedArrayToBST(nums, lo, mid-1), sortedArrayToBST(nums, mid+1, hi));
            
            return node;
        }
        return NULL;
    }
};