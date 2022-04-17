//Time: 6 ms (20.69%), Space: 7.6 MB (93.49%) - LeetHub

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
    TreeNode *head, *last;
public:
    void dfs(TreeNode* node) {
        if (!node) return;
        
        dfs(node->left);
        
        last->right = node;
        node->left = NULL;
        last = node;
        
        dfs(node->right);
    }    
    
    TreeNode* increasingBST(TreeNode* root) {
        head = last = new TreeNode();
        dfs(root);
        return head->right;
    }
};
