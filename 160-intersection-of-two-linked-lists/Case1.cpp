//Time: 56 ms (62.85%), Space: 17.2 MB (13.54%) - LeetHub

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        
        for (; headA; headA = headA->next) 
            set.insert(headA);
        for (; headB; headB = headB->next) 
            if(set.count(headB)) 
                return headB;
        return NULL;
        
    }
};
