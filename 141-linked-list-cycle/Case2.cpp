//Time: 24 ms (14.83%), Space: 7.9 MB (80.64%) - LeetHub
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p1 && p1->next) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1==p2) return true;
        }
        return false;
    }
};
