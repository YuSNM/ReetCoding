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
    int depth = 0;
public:
    void dfs(TreeNode* node, int d) {
        if(node == nullptr) {
            depth = max(depth, d);
            return;
        }
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return depth;
    }
};