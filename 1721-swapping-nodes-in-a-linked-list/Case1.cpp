/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swapval(ListNode *node1, ListNode *node2) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }

    ListNode *swapNodes(ListNode *head, int k) {
        vector<ListNode *> v;

        for (ListNode *node = head; node; node = node->next)  
            v.push_back(node);
        
        swapval(v[k - 1], v[v.size() - k]);
        
        return head;
    }
};
