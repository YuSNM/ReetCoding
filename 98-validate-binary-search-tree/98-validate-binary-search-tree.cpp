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
    long long bef = -1e10;
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return 1;
        
        if(!isValidBST(root->left))
            return false;
        if(root->val <= bef)
            return false;
        bef = root->val;
        if(!isValidBST(root->right))
            return false;
        return true;
    }
};