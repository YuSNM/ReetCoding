//Time: 31 ms (77.05%), Space: 24 MB (87.61%) - LeetHub

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
class BSTIterator {
    stack<TreeNode*> st;
public:
    void LeftTree(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        LeftTree(root);
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right)
            LeftTree(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
