//Time: 19 ms (85.09%), Space: 16.6 MB (96.67%) - LeetHub

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* node) {
        if(!node->left) return;
        
        node->left->next = node->right;        
        if(node->next)
            node->right->next = node->next->left;
        
        dfs(node->right);
        dfs(node->left);
    }
    Node* connect(Node* root) {
        if(root)
            dfs(root);
        return root;
    }
};
