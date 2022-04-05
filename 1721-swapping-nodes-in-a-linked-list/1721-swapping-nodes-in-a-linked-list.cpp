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
    void swapval(int *v1, int *v2) {
        int temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }

    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *left, *right, *node;
        int cnt = 1;
    
        for (left = right = node = head ; node; node = node->next, ++cnt) 
            if(cnt < k) left = left->next;
            else if (cnt > k) right = right->next;
    
        swapval(&left->val, &right->val);

        return head;
    }
};