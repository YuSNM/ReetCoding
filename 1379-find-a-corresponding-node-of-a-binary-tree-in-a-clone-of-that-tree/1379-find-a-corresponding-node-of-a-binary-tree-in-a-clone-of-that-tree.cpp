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
    int val;
    TreeNode* ans;
public:
    void DFS(TreeNode* node) {
        if (!node)
            return;
        else if (node->val == val) {
            ans = node;
            return;
        }
        DFS(node->left);
        DFS(node->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        val = target->val;
        DFS(cloned);
        return ans;
    }
};