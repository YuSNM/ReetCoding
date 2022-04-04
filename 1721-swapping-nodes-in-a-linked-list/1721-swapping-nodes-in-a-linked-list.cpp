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
        int len = 0;
        for (ListNode *node = head; node; node = node->next) 
            ++len;
        int A = k;
        int B = len - k + 1;
        if(A == B) return head;
        else if (A > B) swap(A,B);
        
        ListNode *node1, *node2;
        int i = 1;
        for (node1 = head; i != A; ++i) node1 = node1->next;
        for (node2 = node1; i != B; ++i) node2 = node2->next;
        swapval(node1, node2);
        
        return head;
    }
};