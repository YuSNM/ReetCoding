//Time: 63 ms (29.83%), Space: 33.4 MB (62.62%) - LeetHub

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
    int DFS(TreeNode* root, int n = 0) {
        if (!root) return n;
        
        root->val += DFS(root->right, n);
        return DFS(root->left, root->val);
    }
    TreeNode* convertBST(TreeNode* root) {
        DFS(root);
        return root;
    }
};
