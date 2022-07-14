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
    unordered_map<int, int> inIDX;
    vector<int>::iterator it;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        it = preorder.begin();
        for (int i = 0; i < inorder.size(); i++) 
            inIDX[inorder[i]] = i;
        
        return dfs(inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& inorder, int be, int en) {
        if (be > en)
            return NULL;
        
        TreeNode* node = new TreeNode(*it);
        int mid = inIDX[*it++];
        
        node->left = dfs(inorder, be, mid - 1);
        node->right = dfs(inorder, mid + 1, en);
        return node;
    }
    
};