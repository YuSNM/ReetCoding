//Time: 10 ms (22.52%), Space: 10.7 MB (32.86%) - LeetHub


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
        
        while(n--) p1 = p1->next;
        if(p1 == nullptr) return head->next;
        
        while(p1->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};
