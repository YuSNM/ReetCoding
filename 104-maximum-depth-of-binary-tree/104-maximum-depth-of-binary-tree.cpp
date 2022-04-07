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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> last;
        q.push({root, 1});

        while(!q.empty()) {
            last = q.front(); 
            q.pop();
            if(last.first->left!=nullptr)
                q.push({last.first->left, last.second + 1});
            if(last.first->right!=nullptr)
                q.push({last.first->right, last.second + 1});
        }

        return last.second;
    }
};