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
    int sum;
public:
    void DFS(TreeNode* node) {
        if (!node) return;
        DFS(node->right);
        node->val = sum += node->val;
        DFS(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        DFS(root);
        return root;
    }
};