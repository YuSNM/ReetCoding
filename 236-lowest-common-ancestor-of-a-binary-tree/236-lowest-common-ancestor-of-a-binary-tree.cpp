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
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        
        dfs(node, p, q);
        return ans;
    }
    
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        
        int sum = 0;
        if (node == p || node == q) {
            ans = node;
            return 1;
        }
        if (node->left && dfs(node->left, p, q))
            ++sum;
        if (node->right && dfs(node->right, p, q))
            ++sum;
        
        if (sum == 2) 
            ans = node;
        
        return sum;
    }
};