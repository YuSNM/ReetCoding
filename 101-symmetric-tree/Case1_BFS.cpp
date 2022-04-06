//Time: 14 ms (14.46%), Space: 16.8 MB (7.04%) - LeetHub

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (1) {
            if(q1.empty() || q2.empty()) break;
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();    
            q2.pop();
            if(node1 == nullptr && node2 == nullptr) continue;
            else if(node1 == nullptr ^ node2 == nullptr) return false;
            else if(node1->val != node2->val) return false;

            //왼쪽시작 노드는 왼쪽부터
            q1.push(node1->left);
            q1.push(node1->right);

            //오른쪽 시작 노드는 오른쪽부터 큐삽입
            q2.push(node2->right);
            q2.push(node2->left);

        }
        return true;
    }
};
