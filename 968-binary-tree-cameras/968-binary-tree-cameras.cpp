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

#define CAMERA 0
#define NOCAM 1
#define AROUND 2

class Solution {
    int cam_cnt;
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root) == NOCAM) + cam_cnt;
    }
    
    int dfs(TreeNode* node) {
        
        if (!node)
            return AROUND;
        
        int left = dfs(node->left), right = dfs(node->right);
        
        if (left == NOCAM || right == NOCAM) {
            ++cam_cnt;
            return CAMERA;
        }
        
        return left == CAMERA || right == CAMERA ? AROUND : NOCAM;
    }
};