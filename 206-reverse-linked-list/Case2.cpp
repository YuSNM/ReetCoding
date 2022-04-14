//Time: 11 ms (31.99%), Space: 8.2 MB (79.89%) - LeetHub
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
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *cur = head, *prev = NULL;
        while(cur) {
            next = cur->next;           // 3
            cur->next = prev;           // 2->1
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
