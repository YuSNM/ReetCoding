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
    vector<int> v;
    void func(TreeNode* node) {
        if(node == NULL) return;
        func(node->left);
        v.push_back(node->val);
        func(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        func(root);
        return v;
    }
};