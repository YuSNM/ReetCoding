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
    int deepestLeavesSum(TreeNode* node, int d = 0) {
        if (!node) return 0;
        if (!(deepestLeavesSum(node->left, d + 1) | deepestLeavesSum(node->right, d + 1))) {
            if(d > maxd) {
                sum = node->val;
                maxd = d;
            }else if (d == maxd)
                sum += node->val;
        }
        return sum;
    }
    
};