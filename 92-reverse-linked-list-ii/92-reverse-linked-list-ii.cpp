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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* hhead = new ListNode(0, head), *node1 = hhead, *node2, *node3;
        int i = 1;
        
        for (; i < left; i++)
            node1 = node1->next;
        node2 = node1->next;
        node3 = node2->next;
        
        for (; i < right; i++) {
            
            node2->next = node3->next;
            node3->next = node1->next;
            node1->next = node3;
            
            node3 = node2->next;
        }
        
        return hhead->next;
    }   
};