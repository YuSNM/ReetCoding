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
    
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        for(q.push(root); !q.empty(); q.pop()) {
            if(!q.front()) continue;
            TreeNode *node = q.front();
            q.push(node->left);
            q.push(node->right);
            swap(node->left, node->right);
        }
        
        return root;
    }
};