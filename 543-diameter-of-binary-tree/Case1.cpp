//Time: 7 ms (92.61%), Space: 20.2 MB (92.74%) - LeetHub

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
    int _max;
public:
    int DFS(TreeNode* root) {
        if (!root) return 0;
        
        int left = DFS(root->left);
        int right = DFS(root->right);
        _max = max(_max, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max(_max, DFS(root) - 1);
    }
};
