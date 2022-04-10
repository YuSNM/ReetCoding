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
        for(ListNode *node = head; node; node = node->next) {
            if(node->val == INT_MAX) return true;
            node->val = INT_MAX;
        }
        return false;
    }
};