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
    ListNode* partition(ListNode* node, int x) {
        ListNode *h1, *h2, *t1, *t2;
        
        for (h1 = h2 = t1 = t2 = NULL; node; node = node->next) {
            if (node->val < x) {
                if (h1 == NULL) 
                    h1 = t1 = node;
                else 
                    t1 = t1->next = node;
            }else {
                if (h2 == NULL) 
                    h2 = t2 = node;
                else 
                    t2 = t2->next = node;
            }
        }
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        
        t1->next = h2;
        t2->next = NULL;
        return h1;
    }
};