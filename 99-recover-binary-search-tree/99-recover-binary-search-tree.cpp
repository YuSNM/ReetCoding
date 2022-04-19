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
    vector<pair<int *, int *>> v;
    TreeNode* last_node = NULL;
public:
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);        //inorder 특 좌로 이동, 작업, 우로 이동
        
        if (last_node && last_node->val > node->val) 
            v.push_back({&last_node->val, &node->val});
        last_node = node;
        
        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (v.size() < 2)
            swap(*v[0].first, *v[0].second);
        else
            swap(*v[0].first, *v[1].second);
    }
};