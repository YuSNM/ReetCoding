//Time: 799 ms (33.03%), Space: 165 MB (11.73%) - LeetHub

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
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        int val = target->val;
        
        queue<TreeNode*> q;
        q.push(cloned);
        
        while (1) {
            
            TreeNode* node = q.front();
            if (node->val == val)
                return node;
            
            q.pop();
            
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
};
