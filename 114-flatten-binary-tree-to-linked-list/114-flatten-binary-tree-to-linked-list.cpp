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
    stack<TreeNode*> st;
public:
    void flatten(TreeNode* root) {
        dfs(root);
        if (st.size() < 2)
            return;
        auto temp = st.top();
        st.pop();
        while(!st.empty()) {
            st.top()->right = temp;
            st.top()->left = NULL;
            temp = st.top();
            st.pop();
        }
    }
    
    void dfs(TreeNode* node) {
        if (!node)
            return;
        st.push(node);
        dfs(node->left);
        dfs(node->right);
    }
    
};