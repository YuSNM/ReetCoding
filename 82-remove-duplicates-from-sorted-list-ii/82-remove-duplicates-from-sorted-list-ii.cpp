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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = new ListNode(0, head), *cur = head;
        head = prev;
        
        while (cur && cur->next) 
            if (cur->val != cur->next->val) {
                prev = prev->next = cur;
                cur = prev->next;
            }
            else
                for (int i = cur->val; (cur = cur->next) && cur->val == i;);
            
        prev->next = cur;
        return head->next;
    }
};