//Time: 9 ms (28.37%), Space: 10.7 MB (75.31%) - LeetHub

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
    int last = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head, * p2 = head;
        int len = 1;
        while(p1 = p1->next) 
            len++;
        if((n = len - n) == 0) 
            return head->next;
        while(--n)
            p2 = p2->next;
        
        p2->next = p2->next->next;
        return head;
    }
};
