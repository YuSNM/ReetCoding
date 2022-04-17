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
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        st.push(node);
        dfs(node->right);
    }    
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode *head = st.top();
        head->left = NULL;
        st.pop();
        while (!st.empty()) {
            st.top()->right = head;
            head = st.top();
            head->left = NULL;
            st.pop();
        }
        return head;
    }
};