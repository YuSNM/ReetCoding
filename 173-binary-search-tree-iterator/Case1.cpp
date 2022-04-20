//Time: 49 ms (26.23%), Space: 24.3 MB (22.22%) - LeetHub

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
    vector<int> v;
    int top;
public:
    void BST(TreeNode* node) {
        if (!node) return;
        BST(node->left);
        v.push_back(node->val);
        BST(node->right);
    }
    BSTIterator(TreeNode* root) {
        BST(root);
        top = 0;
    }

    int next() {
        return v[top++];
    }
    
    bool hasNext() {
        return top != v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
