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
    bool DFS(TreeNode* A, TreeNode* B) {
        if(A == nullptr && B == nullptr) return true;
        else if(A == nullptr ^ B == nullptr || A->val != B->val) return false;
        return DFS(A->left, B->right) & DFS(A->right, B->left);
    }

    bool isSymmetric(TreeNode* root) {
        return DFS(root->left, root->right);
    }
};