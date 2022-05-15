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
private:
    int sum = 0;
    int maxd = 0;
public:
    void dfs(TreeNode* node, int d) {
        
        if (!node->left && !node->right) {
            if(d > maxd) {
                sum = node->val;
                maxd = d;
            }else if (d == maxd)
                sum += node->val;
            return;
        }
        if (node->left)
            dfs(node->left, d + 1);
        if (node->right)
            dfs(node->right, d + 1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    
};