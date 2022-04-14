//Time: 11 ms (31.99%), Space: 8.6 MB (10.68%) - LeetHub


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
    ListNode* ReverseHead;
public:
    
    void recur(ListNode* node) {
        if(node->next == NULL) {
            ReverseHead = node;
            return;
        }
        recur(node->next);
        node->next->next = node;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        recur(head);
        head->next = NULL;
        return ReverseHead;
    }
};
