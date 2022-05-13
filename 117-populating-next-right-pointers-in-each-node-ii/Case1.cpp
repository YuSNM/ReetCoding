//Time: 22 ms (34.15%), Space: 17.5 MB (44.54%) - LeetHub

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
    Node* connect(Node* root) {
        if (!root)
            return root;
        
        vector<Node*> *q1 = new vector<Node*>, *q2 = new vector<Node*>;
        q1->push_back(root);
        
        while (!q1->empty()) {
            Node *prev = NULL;
            for (Node *node : (*q1)) {
                if (node->left)
                    q2->push_back(node->left);
                if (node->right)
                    q2->push_back(node->right);
                
                if (prev) 
                    prev->next = node;
                prev = node;
            }
            q1->clear();
            swap(q1, q2);
        }
        delete q1;
        delete q2;
        return root;
    }
};
