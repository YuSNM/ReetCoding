//Time: 17 ms (19.07%), Space: 11.1 MB (60.37%) - LeetHub

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
        if (!head || !head->next) return head;
        
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
