//Time: 1034 ms (5.01%), Space: 164 MB (58.30%) - LeetHub

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!cloned || original == target)
            return cloned;
        
        TreeNode* ans = getTargetCopy(original->left, cloned->left, target);
        if (ans)
            return ans;
        ans = getTargetCopy(original->right, cloned->right, target);
        if (ans)
            return ans;
        return NULL;
    }
};
